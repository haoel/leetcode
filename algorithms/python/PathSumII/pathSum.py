"""
Method 1
"""
def pathSum(self, root, sum):
    if not root: return []
    res = []

    def dfs(root, sum, ls, res):
        if not root.left and not root.right and sum == root.val:
            ls.append(root.val)
            res.append(ls)
        if root.left:
            dfs(root.left, sum - root.val, ls + [root.val], res)
        if root.right:
            dfs(root.right, sum - root.val, ls + [root.val], res)

    dfs(root, sum, [], res)
    return res

"""
Method 2
"""
def pathSum(self, root, sum):
    if not root: return []
    if not root.left and not root.right and root.val == sum: return [[root.val]]
    temp = self.pathSum(root.left, sum - root.val) + self.pathSum(root.right, sum - root.val)
    return [[root.val] + i for i in temp]