def flipMatchVoyage(self, root, voyage):
    res = []
    self.i = 0
    def dfs(root):
        if not root: return True
        if root.val != voyage[self.i]: return False
        self.i += 1
        if root.left and root.left.val != voyage[self.i]:
            res.append(root.val)
            root.left, root.right = root.right, root.left
        return dfs(root.left) and dfs(root.right)
    return res if dfs(root) else [-1]