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
import math
import time


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
            k = target - i
            if (k in nums) == True:
                print "K 值"
                print k, i;
                return
                #  list.append(target - i)

    def primeData(self, target):
        list = [];
        listPrimeData = []
        for i in range(3, target):
            for j in range(2, i):
                if i % j == 0:
                    list.append(i)
                    # print '%d ' % (i)
                    break;
            else:  # for函数也能做判断
                listPrimeData.append(i)

        return listPrimeData

    # expore more
    def primeDataOther(self, n):
        return filter(lambda x: not [x % i for i in range(2, int(math.sqrt(x)) + 1) if x % i == 0], range(2, n + 1))

    #
    # There are two sorted arrays nums1 and nums2 of size m and n respectively.
    #
    # Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
    #
    # Example 1:
    # nums1 = [1, 3]
    # nums2 = [2]
    #
    # The median is 2.0
    # Example 2:
    # nums1 = [1, 2]
    # nums2 = [3, 4]
    #
    # The median is (2 + 3)/2 = 2.5
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        x = len(nums1)
        y = len(nums2)
        z = x + y

        print z

        for i in range(len(nums1)):

    # twoSum(object,[1,2,3],5);
    listAlldata = range(100)
    print time.time()
    # print listAlldata
    print primeData(object, 10000)
    print time.time();
    # print primeData(object,10000)
    print primeDataOther(object, 10000)
    print time.time()
