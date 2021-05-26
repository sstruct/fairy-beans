/*
 * @lc app=leetcode id=20 lang=javascript
 *
 * [20] Valid Parentheses
 */

// @lc code=start
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
  const parentheses = {
    "(": ")",
    "{": "}",
    "[": ']',
    ")": "(",
    "}": "{",
    "]": '['
  }
  const stack = [];
  const arr = s.split("");

  for (let i = 0; i < arr.length; i++) {
    const cur = arr[i];

    if (parentheses[cur] === stack[stack.length -1]) {
      stack.pop()
    } else {
      stack.push(cur);
    }
  }
  return stack.length === 0;
};
// @lc code=end
