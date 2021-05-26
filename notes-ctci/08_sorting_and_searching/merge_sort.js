function mergesort(array) {
  if (array.length < 2) return array;
  let middle = Math.floor(array.length / 2);
  return merge(
    mergesort(array.slice(0, middle)),
    mergesort(array.slice(middle))
  );
}

function merge(left, right) {
  let result = [];
  let il = 0;
  let ir = 0;
  while (il < left.length && ir < right.length) {
    if (left[il] < right[ir]) {
      result.push(left[il++]);
    } else {
      result.push(right[ir++]);
    }
  }
  return result.concat(left.slice(il)).concat(right.slice(ir));
}

let data = [2, 1, 3, 4, 6];

let res = mergesort(data);

console.log("res: ", data, res);
