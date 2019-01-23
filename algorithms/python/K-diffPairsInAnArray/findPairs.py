def findPairs(self, nums, k):
    if k > 0:
        return len(set(nums) & set(a + k for a in nums))
    elif k == 0:
        return sum(v > 1 for v in collections.Counter(nums).values())
    return 0