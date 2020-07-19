# Source : https://leetcode.com/problems/increasing-order-search-tree/
# Author : Arnab Chakraborty
# Date   : 2020-07-19

#***********************************************************************************
# Given a binary search tree, rearrange the tree in in-order so that 
# the leftmost node in the tree is now the root of the tree, and every 
# node has no left child and only 1 right child.
#
#     Example 1:
#       Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]
#
#                    5
#                   / \
#                 3    6
#                / \    \
#               2   4    8
#              /        / \ 
#             1        7   9
#
#       Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
#
#
#*********************************************************************************






# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def __init__(self):
        self.inorder = []
    def increasingBST(self, root: TreeNode) -> TreeNode:
        
        # Using stack        
        stack = []
        ans = []
        
        if root is None:
            return None
        
        current = root
        
        while current is not None or len(stack) > 0:
            while current is not None:
                stack.append(current)
                current = current.left
                
            current = stack.pop()
            ans.append(current.val)
            current = current.right
        
        
        res = TreeNode(ans[0])
        res_head = res
        for i in range(1, len(ans)):
            res.right = TreeNode(ans[i])
            res = res.right
            
        return res_head