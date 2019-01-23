# the same as linked list cycle problem
def findDuplicate(self, nums):
    if len(nums) <= 1: return -1
    slow, fast = nums[0], nums[nums[0]]
    while slow != fast:
        slow = nums[slow]
        fast = nums[nums[fast]]
    
    fast = 0
    while slow != fast:
        slow = nums[slow]
        fast = nums[fast]
    return slow