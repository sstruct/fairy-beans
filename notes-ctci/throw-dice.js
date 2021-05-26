// 扔 n 个骰子，所有骰子和为 m，求每种可能出现的 m 和其出现的概率

// http://kriszhang.com/shaizi_google/
// solution 1: 递归（自顶向下）
function rec1(n, m = 6, sum) {
  if (n === 1) return sum >= 1 && sum <= m ? 1 : 0;
  let count = 0;
  for (let i = 1; i <= m; i++) {
    count = count + rec1(n - 1, m, sum - i);
  }
  return count;
}

function s1(n, m) {
  let result = {};
  for (let i = n; i <= n * m; i++) {
    result[i] = rec1(n, m, i);
  }
  return result;
}

let v1 = s1(2, 6);

// solution 2: 递归（自底向上）
function rec2(n = 2, m = 6) {}

// solution 3: 动态规划

/** 先扔两个试试看 */

// n = 2, m = 6, sum 求 P(sum)
