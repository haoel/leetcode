# Method 1: using set

def containsNearbyDuplicate(self, nums, k):
    if len(nums) <= k + 1: return len(nums) != len(set(nums))
    if k == 0: return False
    s = set(nums[:k])
    for i in range(k, len(nums)):
        if nums[i] in s: return True
        else:
            s.remove(nums[i - k])
            s.add(nums[i])
    return False

# Method 2: using dictionary
def containsNearbyDuplicate(self, nums, k):
    d = {}
    for i, n in enumerate(nums):
        if n in d and i - d[n] <= k:
            return True
        d[n] = i
    return False
