package invertBinaryTree

import (
	"testing"
)

func TestInvertBinaryTree(t *testing.T) {
	root := &node{val: 8}
	nd := &node{val: 6}
	nd1 := &node{val: 10}
	nd2 := &node{val: 5}
	nd3 := &node{val: 7}
	nd4 := &node{val: 9}
	nd5 := &node{val: 11}
	root.left = nd
	root.right = nd1
	nd.left = nd2
	nd.right = nd3
	nd1.left = nd4
	nd1.right = nd5
	result := recursive(root)
	if result.val != 8 ||
		result.left.val != 10 ||
		result.left.left.val != 11 ||
		result.left.right.val != 9 ||
		result.right.val != 6 ||
		result.right.left.val != 7 ||
		result.right.right.val != 5 {
		t.Error("invert fail")
	}
}
