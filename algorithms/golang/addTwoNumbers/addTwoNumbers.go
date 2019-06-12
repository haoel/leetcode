package addTwoNumbers

/**
* Definition for singly-linked list.
* type ListNode struct {
*     Val int
*     Next *ListNode
* }
*/

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	carry, sum := 0, 0
	header := ListNode{}
	tmp := &header

	for {
		sum = carry
		if l1 != nil {
			sum += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}

		tmp.Val = sum%10
		carry = sum/10

		if l1 == nil && l2 == nil {
			break
		}

		tmp.Next = &ListNode{}
		tmp = tmp.Next
	}

	if carry > 0 {
		tmp.Next = &ListNode{Val:carry}
	}
	return &header
}
