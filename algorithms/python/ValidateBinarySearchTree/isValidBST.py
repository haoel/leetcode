# method 1: using recursion

def isValidBST1(self, root, lower = float('-inf'), upper = float('inf')):
    """
    :type root: TreeNode
    :rtype: bool
    """
    if not root: return True
    if root.val <= lower or root.val >= upper: return False
    return self.isValidBST(root.left, lower, min(upper, root.val)) \
        and self.isValidBST(root.right, max(lower, root.val), upper)


# method 2: a proper BST should have this porperty: inorder traversal is increasing
def isValidBST2(self, root):
    inorder = []
    def helper(root):
        if root:
            helper(root.left)
            inorder.append(root.val)
            helper(root.right)
            
    helper(root)
    for i in range(len(inorder) - 1):
        if inorder[i + 1] <= inorder[i]: return False
    return True