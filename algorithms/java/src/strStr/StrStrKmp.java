// Source : https://leetcode.com/problems/implement-strstr/description/
// Inspired by : http://wiki.jikexueyuan.com/project/kmp-algorithm/define.html
// Author : Tianming Cao
// Date   : 2018-02-11

/**********************************************************************************
 * 
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * 
 * Example 1:
 * 
 *  Input: haystack = "hello", needle = "ll"
 *  Output: 2
 *  
 * Example 2:
 * 
 *  Input: haystack = "aaaaa", needle = "bba"
 *  Output: -1
 * 
 **********************************************************************************/
package strStr;

public class StrStrKmp {
	
	/**
	 * KMP-Algorithm
	 */
	public int strStr(String haystack, String needle) {
		if (haystack == null && needle == null) {
			return 0;
		}
		if (haystack == null && needle != null) {
			return -1;
		}
		if (haystack != null && needle == null) {
			return -1;
		}
		int m = haystack.length();
		int n = needle.length();
		if (m < n) {
			return -1;
		}
		if (n == 0) {
			return 0;
		}
		int[] nextArray = getNext(needle);
		int i = 0;
		int j = 0;
		while (i < m) {
			if (j == -1) {
				// If pointer j is in boundary, move i to the right and reset j
				i++;
				j = 0;
			} else {
				if (haystack.charAt(i) == needle.charAt(j)) {
					// While matching succeess, move both pointer i and pointer j to the right
					i++;
					j++;
					if (j == n) {
						return i - n;
					}
				} else {
					/***
					 * For example:
					 * 
					 * next: [-1,0,0,0,0,1,2]
					 * 
					 *                    i
					 *                    ↓ 
					 * haystack:BBC ABCDAB ABCDABCDABDE
					 *                    j
					 *                    ↓
					 * needle:      ABCDABD
					 * 
					 * 
					 * So the next step is:
					 * 
					 *                    i
					 *                    ↓ 
					 * haystack:BBC ABCDAB ABCDABCDABDE
					 *                    j
					 *                    ↓
					 * needle:          ABCDABD
					 */
					j = nextArray[j];
				}
			}
		}
		return -1;
	}
	/**
	 * Generate the next-array of needle string
	 * 
	 * For example:
	 * 
	 * next-array of "ABCDABD" is: [-1,0,0,0,0,1,2]
	 * 
	 * For letter "D", the longest prefix "AB" is equal to the longest suffix "AB", 
	 * the string "AB"'s length is 2, so letter "D"'s next value is 2.
	 */
	public int[] getNext(String str) {
		int len = str.length();
		int[] next = new int[len];
		next[0] = -1;
		int k = -1;
		int j = 0;
		while (j < len - 1) {
			if (k == -1) {
				k = 0;
				next[j + 1] = 0;
				j++;
			} else {
				if (str.charAt(j) == str.charAt(k)) {
					next[j + 1] = k + 1;
					k++;
					j++;
				} else {
					k = next[k];
				}
			}
		}
		return next;
	}
}
