(exports => {
  "use strict";
  // 创建 vdom
  const createElement = (exports.createElement = (type, props, ...children) => {
    props = props != null ? props : {};
    return { type, props, children };
  });
  // 设置事件属性
  const setAttribute = (exports.setAttribute = (dom, key, value) => {
    if (typeof value === "function" && key.startsWith("on")) {
      const eventType = key.slice(2).toLowerCase();
      dom.__gooactHandlers = dom.__gooactHandlers || {};
      dom.removeEventListener(eventType, dom.__gooactHandlers[eventType]);
      dom.__gooactHandlers[eventType] = value;
      dom.addEventListener(eventType, dom.__gooactHandlers[eventType]);
    }
  });
  const render = (exports.render = (vdom, parent = null) => {
    // ⚠️ textContent
    if (parent) parent.textContent = "";
    const mount = parent ? el => parent.appendChild(el) : el => el;
    // string, number 直接显示文字
    if (typeof vdom === "string" || typeof vdom === "number") {
      return mount(document.createTextNode(vdom));
    } else if (typeof vdom === "boolean" || vdom === null) {
      // boolean, null 显示为空字符串，其实也可以不显示
      return mount(document.createTextNode(""));
    } else if (typeof vdom === "object" && typeof vdom.type === "function") {
      // 无状态组件
      return mount(Component.render(vdom));
    } else if (typeof vdom === "object" && typeof vdom.type === "string") {
      // 有状态组件
      // 创建根节点
      const dom = document.createElement(vdom.type);
      // 添加子节点
      for (const child of [].concat(...vdom.children))
        dom.appendChild(render(child));
      // 添加属性
      for (const prop in vdom.props) setAttribute(dom, prop, vdom.props[prop]);
      return mount(dom);
    } else {
      throw new Error(`Invalid VDOM: ${vdom}.`);
    }
  });
  const patch = (exports.patch = (dom, vdom, parent = dom.parentNode) => {
    // （更新 child 并）返回 el
    const replace = parent
      ? el => parent.replaceChild(el, dom) && el
      : el => el;
    if (typeof vdom === "object" && typeof vdom.type === "function") {
      // 无状态组件
      return Component.patch(dom, vdom, parent);
    } else if (typeof vdom !== "object" && dom instanceof Text) {
      // vdom 是文字，dom 也是文字（Text 原生对象），如果不同就更新，否则保持原状
      return dom.textContent !== vdom ? replace(render(vdom)) : dom;
    } else if (typeof vdom === "object" && dom instanceof Text) {
      // vdom 是对象，dom 是文字，是不同的元素，需要更新
      return replace(render(vdom));
    } else if (
      typeof vdom === "object" &&
      dom.nodeName !== vdom.type.toUpperCase()
    ) {
      // vdom 是对象，vdom 和 dom 类型不同，需要更新
      return replace(render(vdom));
    } else if (
      // vdom 是对象，vdom 和 dom 类型相同，继续更新 children
      typeof vdom === "object" &&
      dom.nodeName === vdom.type.toUpperCase()
    ) {
      const pool = {};
      // 记录当前 active 的元素
      const active = document.activeElement;
      // 将 dom 已有的儿子存入 pool
      for (const index in Array.from(dom.childNodes)) {
        const child = dom.childNodes[index];
        const key = child.__gooactKey || key;
        pool[key] = child;
      }
      // 将 vdom 的儿子列出来
      const vchildren = [].concat(...vdom.children);
      // vchildren 根据 pool 里记录的 key 更新组件（为了简略，没有处理多层 key 的情况）
      for (const index in vchildren) {
        const child = vchildren[index];
        const key = (child.props && child.props.key) || index;
        dom.appendChild(pool[key] ? patch(pool[key], child) : render(child));
        delete pool[key];
      }
      // 新 vdom 里不存在的 dom 会被移除
      for (const key in pool) {
        if (pool[key].__gooactInstance)
          pool[key].__gooactInstance.componentWillUnmount();
        pool[key].remove();
      }
      // 移除原生事件，加上 vdom 事件
      for (const attr of dom.attributes) dom.removeAttribute(attr.name);
      for (const prop in vdom.props) setAttribute(dom, prop, vdom.props[prop]);
      active.focus();
      return dom;
    }
  });
  const Component = (exports.Component = class Component {
    constructor(props) {
      // 初始化 props 和 state
      this.props = props || {};
      this.state = null;
    }

    static render(vdom, parent = null) {
      // 初次加载
      // 将 props 和 children 分开管理
      const props = Object.assign({}, vdom.props, { children: vdom.children });
      if (Component.isPrototypeof(vdom.type)) {
        const instance = new vdom.type(props);
        instance.componentWillMount();
        instance.base = render(instance.render(), parent);
        instance.base.__gooactInstance = vdom.props.key;
        instance.componentDidMount();
        return instance.base;
      } else {
        return render(vdom.type(props), parent);
      }
    }

    static patch(dom, vdom, parent = dom.parentNode) {
      const props = Object.assign({}, vdom.props, { children: vdom.children });
      if (
        dom.__gooactInstance &&
        dom.__gooactInstance.constructor === vdom.type
      ) {
        // 已经挂载的 dom ？
        dom.__gooactInstance.componentWillReceiveProps(props);
        dom.__gooactInstance.props = props;
        return patch(dom, dom.__gooactInstance.render());
      } else if (Component.isPrototypeof(vdom.type)) {
        // 还没有挂载的 dom ？
        const ndom = Component.render(vdom);
        return parent ? parent.replaceChild(ndom, dom) && ndom : ndom;
      } else if (!Component.isPrototypeof(vdom.type)) {
        // 还没有挂载的 dom
        return patch(dom, vdom.type(props));
      }
    }

    setState(nextState) {
      if (this.base && this.shouldComponentUpdate(this.props, nextState)) {
        const prevState = this.state;
        this.componentWillUpdate(this.props, nextState);
        this.state = nextState;
        patch(this.base, this.render());
        // ~~prevState 等于 nextState 了~~
        // prevState 在 this.state 被赋新值之前就已经 assign 了
        // 所以它存储的是旧的 this.state 的引用
        this.componentDidUpdate(this.props, prevState);
      } else {
        this.state = nextState;
      }
    }

    shouldComponentUpdate(nextProps, nextState) {
      return nextProps !== this.props || nextState !== this.state;
    }

    componentWillReceiveProps(nextProps) {
      return undefined;
    }

    componentWillUpdate(nextProps, nextState) {
      return undefined;
    }

    componentDidUpdate(prevProps, prevState) {
      return undefined;
    }

    componentWillMount() {
      return undefined;
    }

    componentDidMount() {
      return undefined;
    }

    componentWillUnmount() {
      return undefined;
    }
  });
})(typeof exports !== "undefined" ? exports : (window.Gooact = {}));
