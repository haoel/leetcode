def subsets(self, nums):
    res = []
    def backtracking(temp, start):
        res.append(temp[:])
        for i in range(start, len(nums)):
            temp.append(nums[i])
            backtracking(temp, i + 1)
            temp.pop()
    
    backtracking([], 0)
    return res
    