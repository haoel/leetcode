/*
 * @lc app=leetcode id=3 lang=golang
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.14%)
 * Total Accepted:    863.2K
 * Total Submissions: 3.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 */
func lengthOfLongestSubstring(s string) int {
	size := len(s)
	longest := 0
	for i := 0; i < size; i++ {
		record := make(map[byte]int)
		curr := 0
		for j := i; j < size; j++ {
			_, ok := record[s[j]]
			if ok {
				break
			} else {
				record[s[j]] = j
				curr = curr + 1
			}
		}

		if longest < curr {
			longest = curr
		}
	}

	return longest
}

// another method with sliding window
func lengthOfLongestSubstring2(s string) int {
	n := len(s)

	if n == 0 || n == 1 {
		return n
	}
	
	longest := 0
	start := 0
	memo := make(map[byte]int)
	for i := 0; i < n; i++ {
		idx, ok := memo[s[i]]
		if ok && start < idx + 1 {
			start = idx + 1
		}

		if longest < i - start + 1 {
			longest = i - start + 1
		}

		memo[s[i]] = i
	}

	
	return longest
}

