"""
because of the special porperty of the tree, the question basically is asking to find
the smallest element in the subtree of root. So, we can recursively find left and right
value that is not equal to the root's value, and then return the smaller one of them
"""
def findSecondMinimumValue(self, root):
    if not root: return -1
    if not root.left and not root.right: return -1
    
    left, right = root.left.val, root.right.val
    if left == root.val: left = self.findSecondMinimumValue(root.left)
    if right == root.val: right = self.findSecondMinimumValue(root.right)
    if left != -1 and right != -1: return min(left, right)
    if left == -1: return right
    if right == -1: return left