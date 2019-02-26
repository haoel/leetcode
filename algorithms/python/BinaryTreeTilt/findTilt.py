def findTilt(self, root):
    self.res = 0
    def helper(root):
        if not root: return 0
        left = helper(root.left)
        right = helper(root.right)
        self.res += abs(left - right)
        return root.val + left + right
    helper(root)
    return self.res