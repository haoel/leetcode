# straight forward recursive solution

def lowestCommonAncestor(self, root, p, q):
    if not root: return None
    if root.val > p.val and root.val > q.val:
        return self.lowestCommonAncestor(root.left, p, q)
    elif root.val < p.val and root.val < q.val:
        return self.lowestCommonAncestor(root.right, p, q)
    return root