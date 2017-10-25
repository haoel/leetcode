#!/usr/bin/python
# -*- coding: UTF-8 -*-


# #Given an array of integers, return indices of the two numbers such that they add up to a specific target.
#
# #You may assume that each input would have exactly one solution, and you may not use the same element twice.
#
# #Example:
# #Given nums = [2, 7, 11, 15], target = 9,
#
# #Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].


class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        list = []
        data = nums
        for i in nums:
            k = target -i
            if(k in nums) == True:
                print "K 值"
                print k,i;
                return
          #  list.append(target - i)



        list1 = []

        for j in range(len(nums)):
            list1.append(target - nums[j])
            print list1
        print list;
        print list1;


    twoSum(object,[1,2,3],5);

