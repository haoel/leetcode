package removeLinkedListElements

type listNode struct {
	val  int
	next *listNode
}

func removeElements(head *listNode, k int) *listNode {
	p := &listNode{next: head}
	h := p
	for h.next != nil {
		if h.next.val == k {
			h.next = h.next.next
		} else {
			h = h.next
		}
	}
	return p.next
}
