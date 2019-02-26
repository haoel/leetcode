"""
straight forward recursive solution:
if left node is leave, add the value and the the right subtree
if not, then recursively call left and right subtree
"""
def sumOfLeftLeaves(self, root):
    if not root: return 0
    if root.left and not root.left.left and not root.left.right:
        return root.left.val + self.sumOfLeftLeaves(root.right)
    return self.sumOfLeftLeaves(root.left) + self.sumOfLeftLeaves(root.right)