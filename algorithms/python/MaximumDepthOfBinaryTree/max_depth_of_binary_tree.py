# Source : https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
# Author : Arnab Chakraborty
# Date   : 2020-07-19

#**********************************************************************************
#
# Given a binary tree, find its maximum depth.
#
# The maximum depth is the number of nodes along the longest path from the root node
# down to the farthest leaf node.
#
#**********************************************************************************




"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def maxDepth(self, root: 'Node', depth=1) -> int:
        if root is None:
            return 0
        
        depth = 0
        for child in root.children:
            depth = max([depth, self.maxDepth(child)])
            
        print(root.val, depth + 1)
            
        return depth + 1