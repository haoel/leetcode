def buildTree(self, inorder, postorder):
    if inorder:
        i = inorder.index(postorder.pop())
        root = TreeNode(inorder[i])
        root.right = self.buildTree(inorder[i+1:], postorder)
        root.left = self.buildTree(inorder[:i], postorder)
        return root