# Source : https://leetcode.com/problems/maximum-average-subarray-i/
#
# Given an integer array nums and an integer k, find the contiguous subarray
# of length k that has the maximum average value and return this value.


class Solution(object):
    # Method 1: sliding window
    # Time: O(n)  Space: O(1)
    def findMaxAverage(self, nums, k):
        total = 0
        best = float('-inf')
        for i, n in enumerate(nums):
            total += n
            if i >= k:
                total -= nums[i - k]
            if i >= k - 1:
                best = max(best, total)
        return best / k

    # Method 2: prefix sum
    # Time: O(n)  Space: O(n)
    def findMaxAverage_prefix_sum(self, nums, k):
        prefix = [0]
        for n in nums:
            prefix.append(prefix[-1] + n)

        res = max(prefix[i + k] - prefix[i] for i in range(len(nums) - k + 1))
        return res / k
