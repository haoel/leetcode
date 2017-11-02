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
            k = target -i
            if(k in nums) == True:
                print "K 值"
                print k,i;
                return
          #  list.append(target - i)

    def primeData(self,target):
        list = [];
        listPrimeData = []
        for i in range(3,target):
            for j in range(2,i):
                if i%j==0:
                    list.append(i)
                    #print '%d ' % (i)
                    break;
            else :#for函数也能做判断
                listPrimeData.append(i)

        return listPrimeData
    #expore more
    def primeDataOther(self,n):
        return filter(lambda x: not [x%i for i in range(2, int(math.sqrt(x))+1) if x%i ==0], range(2,n+1))



    #twoSum(object,[1,2,3],5);
    listAlldata = range(100)
    print time.time()
    #print listAlldata
    print primeData(object,10000)
    print time.time();
    #print primeData(object,10000)
    print primeDataOther(object,10000)
    print time.time()
