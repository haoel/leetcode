def dominantIndex(self, nums):
    i = nums.index(max(nums))
    l = nums[i]
    del nums[i]
    if not nums: return 0
    return i if l >= 2 * max(nums) else -1