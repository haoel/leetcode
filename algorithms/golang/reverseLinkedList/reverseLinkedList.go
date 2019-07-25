/**
 * Definition for singly-linked list.
 * type ListNode struct {
 * Val int
 * Next *ListNode
 * }
 */
 func reverseList(head *ListNode) *ListNode {
    if head == nil {
        return head
    }
    var p *ListNode = head
    var newH *ListNode = nil
    for p != nil {
        var pNext *ListNode = p.Next
        p.Next, newH, p = newH, p, pNext
    }
    return newH

}