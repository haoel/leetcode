// Source : https://leetcode.com/problems/valid-anagram/description/
// Author : Tianming Cao
// Date   : 2018-02-11

/**********************************************************************************
 * 
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 * 
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your solution to such case?
 * 
 **********************************************************************************/
package validAnagram;

public class ValidAnagram {
	
	/**
	 * Like counting-sort
	 */
	public boolean isAnagram(String s, String t) {
		if (s == null && t == null) {
			return true;
		}
		if (s.length() != t.length()) {
			return false;
		}
		final int mapLen = 26;
		int[] map1 = new int[mapLen];
		int[] map2 = new int[mapLen];
		int len = s.length();
		for (int i = 0; i < len; i++) {
			char c1 = s.charAt(i);
			map1[c1 - 'a']++;
			// ASCII of letter a is 97
			int c2 = t.charAt(i);
			map2[c2 - 97]++;
		}
		for (int i = 0; i < mapLen; i++) {
			if (map1[i] != map2[i]) {
				return false;
			}
		}
		return true;
	}
	
}
