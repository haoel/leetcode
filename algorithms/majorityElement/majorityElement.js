/****
 * Solution of https://leetcode.com/problems/majority-element/
 * @author: Jerry Zou
 * @date: 2015.6.4
 **/

/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    var hash = {},
        i;

    for (i = 0; i < nums.length; i++) {
        hash[nums[i]] = hash[nums[i]] ? hash[nums[i]]+1 : 1;
    }

    var keys = Object.keys(hash),
        max = 0,
        result;
    for (i = 0; i < keys.length; i++) {
        if (hash[keys[i]] > max) {
            result = keys[i];
            max = hash[keys[i]];
        }
    }

    return parseFloat(result);
};