/*
 * @lc app=leetcode id=98 lang=javascript
 *
 * [98] Validate Binary Search Tree
 */
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isValidBST = function(root) {
  function helper(node, min, max) {
    if (node === null) return true;
    return (
      max === null ||
      node.val < max ||
      (min === null || node.val > min) ||
      (helper(node.left, min, node.val) && helper(node.right, node.val, max))
    );
  }
  return helper(root, null, null);
};
