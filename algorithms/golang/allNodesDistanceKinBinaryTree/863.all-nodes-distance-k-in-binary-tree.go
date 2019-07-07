/*
 * @lc app=leetcode id=863 lang=golang
 *
 * [863] All Nodes Distance K in Binary Tree
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */ 
 func distanceK(root *TreeNode, target *TreeNode, K int) []int {
	output := []int{}
	path := []*TreeNode{}
	isExist := findPath(root, target, &path )

	if isExist {
		var prev *TreeNode
		for index, node := range(path) {
			output = append(output, distanceFromChildren(node, prev, K - index)...)
			prev = node
		}
	}

	return output
}

func distanceFromChildren(root *TreeNode, prev *TreeNode, M int) []int {
	output := []int{}
	if M < 0 {
		return output
	} else if M == 0 {
		output = append(output, root.Val)
	}

	if root.Left != nil && root.Left != prev {
		output = append(output, distanceFromChildren(root.Left, nil, M - 1)...) 
	}
	
	if root.Right != nil && root.Right != prev {
		output = append(output, distanceFromChildren(root.Right, nil, M - 1)...) 
	}

	return output
}

func findPath(root, target *TreeNode, memo *[]*TreeNode) bool {
	if root == nil {
		return false
	}

	existLeft := findPath(root.Left, target, memo)
	existRight := findPath(root.Right, target, memo)
	if target == root || existLeft || existRight {
		*memo = append(*memo, root)
		return true
	}

	return false
}
