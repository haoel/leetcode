/****
 * Solution of https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * @author: Jerry Zou
 * @date: 2015.6.4
 **/

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    var i = 0, j = 0,
        maxLen = 0;

    while (j < s.length) {
        if (s.substring(i, j).indexOf(s[j]) < 0) {
            j++;
            maxLen = Math.max(maxLen, j - i);
        } else {
            i++;
        }
    }

    return maxLen;
};