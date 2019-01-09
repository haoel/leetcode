def lowestCommonAncestor(self, root, p, q):
    if root in (None, p, q): return root
    left = self.lowestCommonAncestor(root.left, p, q)
    right = self.lowestCommonAncestor(root.right, p, q)
    return root if left and right else left or right