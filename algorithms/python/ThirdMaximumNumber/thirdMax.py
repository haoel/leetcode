def thirdMax(self, nums):
    if len(set(nums)) < 3: return max(nums)
    first = second = third = float('-inf')
    for n in nums:
        if n > first:
            third = second
            second = first
            first = n
        elif second < n < first:
            third = second
            second = n
        elif third < n < second:
            third = n
    return third