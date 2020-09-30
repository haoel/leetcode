# question : https://leetcode.com/problems/first-missing-positive/
# Author : Samir Rajesh Prajapati
# Date : 2020-10-01

# ********************************************************************************* 
# * 
# * Given an unsorted integer array, find the first missing positive integer.
# * 
# * For example,
# * Given [1,2,0] return 3,
# * and [3,4,-1,1] return 2.
# * 
# * Your algorithm should run in O(n) time and uses constant space.
# * 
# *               
# **********************************************************************************

class Solution:
    def firstMissingPositive(self, nums: [int]) -> int:
        for i in range(len(nums)):
            while nums[i]>0 and nums[i]<len(nums) and nums[i]-1!=i and nums[i]!=nums[nums[i]-1]:
                nums[nums[i]-1], nums[i] = nums[i], nums[nums[i]-1]
        for i in range(len(nums)):
            if i + 1 != nums[i]:
                return i + 1 
        return len(nums) + 1
                
if __name__ == '__main__':
    number = Solution()
    print(number.firstMissingPositive([3,4,-1,1]))
