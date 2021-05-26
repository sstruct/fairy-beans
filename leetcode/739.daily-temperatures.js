/*
 * @lc app=leetcode id=739 lang=javascript
 *
 * [739] Daily Temperatures
 */

// @lc code=start
/**
 * @param {number[]} T
 * @return {number[]}
 */
var dailyTemperatures = function(T) {
  const res = [];
  const stack = [];
  for (let i = T.length - 1; i >= 0; --i) {
    while(stack.length > 0 && T[i] >= T[stack[stack.length - 1]]) stack.pop();
    res[i] = stack.length === 0 ? 0 : stack[stack.length - 1] - i;
    stack.push(i)
  }
  return res;
};
// @lc code=end
