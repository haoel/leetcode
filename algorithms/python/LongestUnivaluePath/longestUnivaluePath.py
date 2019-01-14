def longestUnivaluePath(self, root):
    self.longest = 0
    def helper(root):
        if not root: return 0
        l, r = helper(root.left), helper(root.right)
        left = (l + 1) if root.left and root.left.val == root.val else 0
        right = (r + 1) if root.right and root.right.val == root.val else 0
        self.longest = max(self.longest, left + right)
        return max(left, right)
    helper(root)
    return self.longest