/*
 * @lc app=leetcode id=707 lang=javascript
 *
 * [707] Design Linked List
 *
 * https://leetcode.com/problems/design-linked-list/description/
 *
 * algorithms
 * Medium (26.39%)
 * Likes:    1011
 * Dislikes: 980
 * Total Accepted:    134.5K
 * Total Submissions: 509.7K
 * Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n' +
  '[[],[1],[3],[1,2],[1],[1],[1]]'
 *
 * Design your implementation of the linked list. You can choose to use a
 * singly or doubly linked list.
 * A node in a singly linked list should have two attributes: val and next. val
 * is the value of the current node, and next is a pointer/reference to the
 * next node.
 * If you want to use the doubly linked list, you will need one more attribute
 * prev to indicate the previous node in the linked list. Assume all nodes in
 * the linked list are 0-indexed.
 * 
 * Implement the MyLinkedList class:
 * 
 * 
 * MyLinkedList() Initializes the MyLinkedList object.
 * int get(int index) Get the value of the index^th node in the linked list. If
 * the index is invalid, return -1.
 * void addAtHead(int val) Add a node of value val before the first element of
 * the linked list. After the insertion, the new node will be the first node of
 * the linked list.
 * void addAtTail(int val) Append a node of value val as the last element of
 * the linked list.
 * void addAtIndex(int index, int val) Add a node of value val before the
 * index^th node in the linked list. If index equals the length of the linked
 * list, the node will be appended to the end of the linked list. If index is
 * greater than the length, the node will not be inserted.
 * void deleteAtIndex(int index) Delete the index^th node in the linked list,
 * if the index is valid.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get",
 * "deleteAtIndex", "get"]
 * [[], [1], [3], [1, 2], [1], [1], [1]]
 * Output
 * [null, null, null, null, 2, null, 3]
 * 
 * Explanation
 * MyLinkedList myLinkedList = new MyLinkedList();
 * myLinkedList.addAtHead(1);
 * myLinkedList.addAtTail(3);
 * myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
 * myLinkedList.get(1);              // return 2
 * myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
 * myLinkedList.get(1);              // return 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= index, val <= 1000
 * Please do not use the built-in LinkedList library.
 * At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and
 * deleteAtIndex.
 * 
 * 
 */

// @lc code=start
/**
 * Initialize your data structure here.
 */
var MyLinkedList = function() {
  this.head = null;
};

var LinkedListNode = function(val = null) {
  this.val = val;
  this.next = null;
}

MyLinkedList.prototype.size = function() {
  let count = 0;
  let cur = this.head;
  while (cur !== null) {
    count++;
    cur = cur.next;
  }
  return count;
}

/**
 * Get the value of the index-th node in the linked list. If the index is invalid, return -1. 
 * @param {number} index
 * @return {number}
 */
MyLinkedList.prototype.get = function(index) {
  if (index >= this.size()) {
    return -1;
  }
  let cur = this.head;
  for (let i = 0; i < index; i++) {
    cur = cur.next;
  }
  return cur.val;
};

/**
 * Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtHead = function(val) {
  const node = new LinkedListNode(val);
  /**
   * 边界情况：单独处理 head 为空
   */
  if (this.head === null) {
    this.head = node;
  } else {
    node.next = this.head;
    this.head = node;
  }
};

/**
 * Append a node of value val to the last element of the linked list. 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtTail = function(val) {
  /**
   * 边界情况：单独处理 head 为空
   */
  if (this.head === null) {
    this.addAtHead(val);
  } else {
    const node = new LinkedListNode(val);
    let cur = this.head;
    let size = this.size();
    for (let i = 0; i < size - 1; i++) {
      cur = cur.next;
    }
    cur.next = node;
  }
};

/**
 * Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. 
 * @param {number} index 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtIndex = function(index, val) {
  /**
   * 边界情况：index === size 时，需要处理插入到最后的逻辑
   * 此情况已经包含在最终分支逻辑中
   */
  if (index > this.size()) {
    return;
  }
  /**
   * 边界情况：插入 index 是 0 时，单独处理 head 逻辑
   */
  if (index === 0) {
    this.addAtHead(val);
    return;
  } 
  const node = new LinkedListNode(val);
  let cur = this.head;
  for (let i = 0; i < index - 1; i++) {
    cur = cur.next;
  }
  node.next = cur.next;
  cur.next = node;
};

/**
 * Delete the index-th node in the linked list, if the index is valid. 
 * @param {number} index
 * @return {void}
 */
MyLinkedList.prototype.deleteAtIndex = function(index) {
  if (index >= this.size()) {
    return;
  }
  /**
   * 边界情况：index === 0 时，单独处理 head。类似的 addAtIndex 也需要这样的处理
   */
  if (index === 0) {
    this.head = this.head.next;
    return;
  }
  let cur = this.head;
  for (let i = 0; i < index - 1; i++) {
    cur = cur.next;
  }
  cur.next = cur.next.next;
};

/** 
 * Your MyLinkedList object will be instantiated and called as such:
 * var obj = new MyLinkedList()
 * var param_1 = obj.get(index)
 * obj.addAtHead(val)
 * obj.addAtTail(val)
 * obj.addAtIndex(index,val)
 * obj.deleteAtIndex(index)
 */
// @lc code=end

