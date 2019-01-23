# simply find the three largest and two smallest
# Method 1: sort
def maximumProduct(self, nums):
    nums.sort()
    return max(nums[0] * nums[1] * nums[-1], nums[-1] * nums[-2] * nums[-3])

# Method 2: using heapq, O(n) time
def maximumProduct(self, nums):
    import heapq
    a, b = heapq.nlargest(3, nums), heapq.nsmallest(2, nums)
    return max(a[0] * a[1] * a[2], a[0] * b[0] * b[1])