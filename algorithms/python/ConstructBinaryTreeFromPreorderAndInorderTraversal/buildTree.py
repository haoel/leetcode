def buildTree(self, preorder, inorder):
    if inorder:
        i = inorder.index(preorder.pop(0))
        root = TreeNode(inorder[i])
        root.left = self.buildTree(preorder, inorder[:i])
        root.right = self.buildTree(preorder, inorder[i+1:])
        return root