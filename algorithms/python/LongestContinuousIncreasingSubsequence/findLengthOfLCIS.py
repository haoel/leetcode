def findLengthOfLCIS(self, nums):
    if not nums: return 0
    res = 1
    temp = 1
    for i in range(1, len(nums)):
        if nums[i] > nums[i - 1]:
            temp += 1
        else:
            res = max(temp, res)
            temp = 1
    return max(temp, res)