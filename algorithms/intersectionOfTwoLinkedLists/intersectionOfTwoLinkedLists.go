package intersectionOfTwoLinkedLists

type listNode struct {
	val  int
	next *listNode
}

func getIntersectionNode(a *listNode, b *listNode) *listNode {
	al := getLength(a)
	bl := getLength(b)

	if al == 0 || bl == 0 {
		return nil
	}
	if al < bl {
		a, b = b, a
	}
	for i := 0; i < abs(al, bl); i++ {
		a = a.next
	}

	for a != b {
		a = a.next
		b = b.next
	}
	return a
}

func getLength(l *listNode) int {
	count := 0
	for l != nil {
		count++
		l = l.next
	}
	return count
}

func abs(a, b int) int {
	if c := a - b; c < 0 {
		return -c
	} else {
		return c
	}
	return 0
}
