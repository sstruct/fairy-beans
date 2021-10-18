/*
 * @lc app=leetcode id=19 lang=javascript
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (36.68%)
 * Likes:    7208
 * Dislikes: 369
 * Total Accepted:    1.1M
 * Total Submissions: 2.9M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, remove the n^th node from the end of the
 * list and return its head.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1], n = 1
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1,2], n = 1
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 * 
 * 
 * 
 * Follow up: Could you do this in one pass?
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
 var removeNthFromEnd = function(head, n) {
  let slow = head;
  let fast = head;
  for (let i = 0; i < n; i++) {
    fast = fast.next;
  }
  /**
   * fast === null，说明 n === sz，对头指针需要单独处理
   */
  if (fast === null) return head.next;
  /**
   * 继续遍历，当 fast.next 时停止，此时 slow 为 需要删除节点的上一个节点。
   */
  while (fast.next !== null) {
    fast = fast.next;
    slow = slow.next;
  }
  slow.next = slow.next.next;
  return head;
};
// @lc code=end
