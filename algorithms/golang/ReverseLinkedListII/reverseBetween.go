/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func reverseBetween(head *ListNode, m int, n int) *ListNode {
    var dummy *ListNode = &ListNode{0, nil}
    dummy.Next = head
    pre := dummy
    for i := 1; i < m; i++ {
        pre = pre.Next
    }
    cur := pre.Next
    for i := m; i < n; i++ {
        nxt := cur.Next
        cur.Next = nxt.Next
        nxt.Next = pre.Next
        pre.Next = nxt
    }
    return dummy.Next
}