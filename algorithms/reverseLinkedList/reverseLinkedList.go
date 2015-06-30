package reverseLinkedList

type listNode struct {
	val  int
	next *listNode
}

func iteratively(head *listNode) *listNode {
	var p, q *listNode
	for {
		if head == nil {
			break
		}
		q = head.next
		head.next = p
		p = head
		head = q
	}
	return p
}

func recursively(head *listNode) *listNode {
	if head == nil || head.next == nil {
		return head
	}

	n := recursively(head.next)
	head.next.next = head
	head.next = nil
	return n
}
