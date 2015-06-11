/****
 * Solution of https://leetcode.com/problems/two-sum/
 * @author: Jerry Zou
 * @date: 2015.6.4
 **/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var i, j, num, hash = {};

    for (i = 0; i < nums.length; i++) {
        hash[nums[i]] = i + 1;
    }
    for (i = 0; i < nums.length; i++) {
        j = hash[target - nums[i]];
        if (j && j !== i + 1) {
            i = i + 1;
            return i < j ? [i, j] : [j, i];
        }
    }
    return [-1, -1];
};