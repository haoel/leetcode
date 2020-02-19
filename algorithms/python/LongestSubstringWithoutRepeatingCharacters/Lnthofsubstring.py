[Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
"""
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
"""
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        dic = {}
        max_so_far = 0
        curr_max = 0
        start = 0
        for index,i in enumerate(s):
            if i in dic and dic[i] >=start:
                max_so_far = max(max_so_far,curr_max)
                curr_max = index - dic[i]
                start = dic[i] + 1
            else:
                curr_max += 1
            dic[i] = index
        return max(max_so_far,curr_max)  
