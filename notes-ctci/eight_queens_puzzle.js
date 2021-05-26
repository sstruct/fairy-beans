// Eight queens puzzle -> backtracking algorithms

// Given n queens and one chessboard of length of n. Find out all solutions that every queen won't touch each other.
// For example, when n = 1, return [[[1, 1]]], when n = 2, return []

function so1(n) {
  let res = [];
  if (n === 1) res.push([[1, 1]]);

  for (let i = 1; i <= n; i++) {
    //
  }

  return res;
}
