package invertBinaryTree

type node struct {
	val         int
	left, right *node
}

func recursive(root *node) *node {
	if root == nil {
		return root
	}
	nd := recursive(root.left)
	root.left = recursive(root.right)
	root.right = nd
	return root
}
