package removeLinkedListElements

import (
	"testing"
)

func TestRemoveElements(t *testing.T) {
	l := &listNode{val: 0}
	l1 := &listNode{val: 1}
	l2 := &listNode{val: 2}
	l3 := &listNode{val: 3}
	l.next = l1
	l1.next = l2
	l2.next = l3
	r := removeElements(l, 1)
	if r.val != 0 ||
		r.next.val != 2 ||
		r.next.next.val != 3 {
		t.Error("fail")
	}
}
