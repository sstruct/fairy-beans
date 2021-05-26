/*
 * @lc app=leetcode id=752 lang=javascript
 *
 * [752] Open the Lock
 */

// @lc code=start
/**
 * @param {string[]} deadends
 * @param {string} target
 * @return {number}
 */
/**
 * @param {string[]} deadends
 * @param {string} target
 * @return {number}
 */

var openLock = function(deadends, target) {
    let queue = [];
    let visited = new Set();
    let step = -1;
    const root = "0000";
  
    if (deadends.includes(root) || deadends.includes(target)) {
        return step
    }
  
    function parseValue(val) {
        return val.split("").map(Number);
    }
    function stringifyValue(arr) {
        return arr.join("");
    }
    function getDigitNeighbor(digit) {
        if (digit === 0) return [9, 1];
        if (digit === 9) return [8, 0];
        return [digit - 1, digit + 1];
    }
    function getNeighbors(val) {
        let res = [];
        let arr = parseValue(val);
        for (let i = 0; i < arr.length; i++) {
            let [leftDigitNeighbor, rightDigitNeighbor] = getDigitNeighbor(arr[i]);
            let left = [...arr];
            left[i] = leftDigitNeighbor;
            let right = [...arr];
            right[i] = rightDigitNeighbor;
            res = res.concat([left, right])
        }
        return res.map(stringifyValue);
    }
  
    queue.push(root);
    visited.add(root);
    
    while (queue.length) {
        step += 1;
        // ⚠️ size important!!!
        // if write in the following for loop, it will be dynamic
        let size = queue.length;
  
        for (let i = 0; i < size; i++) {
            const cur = queue.shift();
            if (cur === target) return step;
            const neighbors = getNeighbors(cur);
  
            for (let j = 0; j < neighbors.length; j++) {
                const neighbor = neighbors[j];
                if (!visited.has(neighbor) && !deadends.includes(neighbor)) {
                    queue.push(neighbor);
                    visited.add(neighbor);
                }
            }
  
        }
    }
    return -1;
};
  
// openLock(["0201","0101","0102","1212","2002"], "0202")
// @lc code=end
