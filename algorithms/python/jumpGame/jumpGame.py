# Source : https://leetcode.com/problems/jump-game/
# Author : Sudesh Chaudhary
# Date   : 2020-10-01

#  Given an array of non-negative integers, you are initially positioned at the first index of the array.

#  Each element in the array represents your maximum jump length at that position.

#  Determine if you are able to reach the last index.

#  For example:
#  A = [2,3,1,1,4], return true.

#  A = [3,2,1,0,4], return false.


# Solution
# time O(n) space O(1)

# traverse array, maintain the most far we can go
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        # max index where we can go
        farest = 0;
        for i in range(n):
            if i > farest:
                return False
            farest = max(farest, i + nums[i])
        return True
