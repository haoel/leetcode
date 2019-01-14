def pathSum(self, root, target):
    self.result = 0
    cache = {0:1}
    
    def dfs(root, currPathSum):
        if not root: return  

        currPathSum += root.val
        oldPathSum = currPathSum - target

        self.result += cache.get(oldPathSum, 0)
        cache[currPathSum] = cache.get(currPathSum, 0) + 1


        dfs(root.left, currPathSum)
        dfs(root.right, currPathSum)

        cache[currPathSum] -= 1
    
    dfs(root, 0)
    return self.result