package reverseLinkedList

import (
	"testing"
)

func TestIteratively(t *testing.T) {
	l := &listNode{val: 0}
	l1 := &listNode{val: 1}
	l2 := &listNode{val: 2}
	l3 := &listNode{val: 3}
	l.next = l1
	l1.next = l2
	l2.next = l3

	r := iteratively(l)
	if r.val != 3 ||
		r.next.val != 2 ||
		r.next.next.val != 1 ||
		r.next.next.next.val != 0 {
		t.Error("fail")
	}
}

func TestRecursively(t *testing.T) {
	l := &listNode{val: 0}
	l1 := &listNode{val: 1}
	l2 := &listNode{val: 2}
	l3 := &listNode{val: 3}
	l.next = l1
	l1.next = l2
	l2.next = l3

	r := recursively(l)
	if r.val != 3 ||
		r.next.val != 2 ||
		r.next.next.val != 1 ||
		r.next.next.next.val != 0 {
		t.Error("fail")
	}
}
