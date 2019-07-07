/*
 * @lc app=leetcode id=2 lang=golang
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (30.82%)
 * Total Accepted:    818.5K
 * Total Submissions: 2.7M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	result := &ListNode{}
	carry := 0
	sum := 0
	curr := result
	for {
		if l1 == nil && l2 == nil  {
			if carry == 1 {
				curr.Next = &ListNode{}
				curr = curr.Next
				curr.Val = 1
			}
			break
		} 

		curr.Next = &ListNode{}
		curr = curr.Next

		v1 := 0
		v2 := 0
		if l1 != nil {
			v1 = l1.Val
			l1 = l1.Next
		}

		if l2 != nil {
			v2 = l2.Val
			l2 = l2.Next
		}

		sum = v1 + v2 + carry
		curr.Val = sum % 10

		if sum >= 10 {
			carry = 1
		} else {
			carry = 0
		}
	}

	return result.Next
}

