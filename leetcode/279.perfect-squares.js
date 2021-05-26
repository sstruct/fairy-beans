/*
 * @lc app=leetcode id=279 lang=javascript
 *
 * [279] Perfect Squares
 */

// @lc code=start
/**
 * @param {number} n
 * @return {number}
 */
var numSquares = function(n) {
  // Thought: it seems easier to use recursive function to solve
  // Dynamic programming
  if (n < 1) return -1

  let step = -1;
  let queue = [];
  let visited = new Set();

  queue.push(n);
  visited.add(n);
  let maxRoot = parseInt(Math.sqrt(n));

  while (queue.length) {
    step += 1;
    let size = queue.length;
    for (let i = 0; i < size; i++) {
      let cur = queue.shift();
      if (cur === 0) return step;
      for (let j = maxRoot; j > 0; j--) {
        const val = cur - j ** 2;
        if (val >= 0 && !visited.has(val)) {
          queue.push(val);
          visited.add(val);
        }
      }
    }
  }
  return -1;
};
// @lc code=end