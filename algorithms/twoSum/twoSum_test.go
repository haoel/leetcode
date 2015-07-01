package twoSum

import (
	"testing"
)

func TestTwoSum3(t *testing.T) {
	ts := newTwoSum3()
	ts.add(1)
	ts.add(3)
	ts.add(5)
	if !ts.find(4) {
		t.Error("fail")
	}
	if ts.find(7) {
		t.Error("fail")
	}
}
