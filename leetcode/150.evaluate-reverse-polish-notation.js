/*
 * @lc app=leetcode id=150 lang=javascript
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
  const operations = ["+", "-", "*", "/"];
  const stack = [];
  function op(str, left, right) {
    switch(str) {
      case "+": return left + right;
      case "-": return left - right;
      case "*": return left * right;
      case "/": return parseInt(left / right);
    }
  }
  for (let i = 0; i < tokens.length; i++) {
    let cur = tokens[i];
    if (operations.includes(cur)) {
      let right = stack.pop();
      let left = stack.pop();
      stack.push(op(cur, left, right));
    } else {
      stack.push(Number(cur));
    }
  }
  return stack.pop()
};
// @lc code=end

