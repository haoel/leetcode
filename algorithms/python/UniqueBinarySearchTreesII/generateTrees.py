def generateTrees(self, n):
    if n == 0: return []
    
    def helper(start, end):
        ls = []
        if start > end:
            ls.append(None)
            return ls
        if start == end:
            ls.append(TreeNode(start))
            return ls
        
        for i in range(start, end + 1):
            left = helper(start, i - 1)
            right = helper(i + 1, end)
            for lnode in left:
                for rnode in right:
                    root = TreeNode(i)
                    root.left = lnode
                    root.right = rnode
                    ls.append(root)
        return ls
    
    return helper(1, n)