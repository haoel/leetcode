def containsNearbyAlmostDuplicate(self, nums, k, t):
    if k < 1 or t < 0: return False
    d = {}
    w = t + 1
    for i, n in enumerate(nums):
        m = n // w
        if m in d: return True
        if m - 1 in d and abs(d[m-1] - n) <= t: return True
        if m + 1 in d and abs(d[m+1] - n) <= t: return True
        d[m] = n
        if i >= k: del d[nums[i - k] // w]
    return False