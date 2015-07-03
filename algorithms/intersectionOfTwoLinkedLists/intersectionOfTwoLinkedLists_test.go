package intersectionOfTwoLinkedLists

import (
	"testing"
)

func TestIntersectionOfTwoLinkedLists(t *testing.T) {
	c3 := &listNode{100, nil}
	c2 := &listNode{10, c3}
	c1 := &listNode{1, c2}

	a2 := &listNode{20, c1}
	a1 := &listNode{2, a2}

	b3 := &listNode{300, c1}
	b2 := &listNode{30, b3}
	b1 := &listNode{3, b2}

	if getIntersectionNode(a1, b1) != c1 {
		t.Error("fail")
	}
}
