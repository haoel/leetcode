package minStack

import (
	"testing"
)

func TestMinStack(t *testing.T) {
	stack := stack{}
	//no data exist
	if stack.getMin() != 0 {
		t.Error("fail")
	}
	if stack.top() != 0 {
		t.Error("fail")
	}
	stack.push(1)
	stack.push(2)
	if stack.top() != 2 {
		t.Error("fail")
	}
	stack.pop()
	if stack.getMin() != 1 {
		t.Error("fail")
	}
	stack.push(-1)
	if stack.getMin() != -1 {
		t.Error("fail")
	}
	stack.pop()
	if stack.getMin() != 1 {
		t.Error("fail")
	}
}
