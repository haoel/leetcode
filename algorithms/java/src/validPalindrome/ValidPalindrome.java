// Source : https://leetcode.com/problems/valid-palindrome/description/
// Author : Tianming Cao
// Date   : 2018-02-11

/**********************************************************************************
 * 
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * 
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * 
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 * 
 * For the purpose of this problem, we define empty string as valid palindrome.
 * 
 **********************************************************************************/
package validPalindrome;

public class ValidPalindrome {
	private boolean isAlphaNumber(char c) {
		if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
			return true;
		} else {
			return false;
		}
	}
	/**
	 * We need two pointers like below:
	 * 
	 *  i                   j   
	 *  ↓------->  <--------↓
	 *  a,b c d e e d;c b a +
	 *  
	 *  Move them from border to mid, util i meet j or s[i]!=s[j]
	 */
	public boolean isPalindrome(String s) {
		if (s == null || s.length() <= 1) {
			return true;
		}
		s = s.toLowerCase();
		int i = 0, j = s.length() - 1;
		while (i < j) {
			while (!isAlphaNumber(s.charAt(i)) && i < j) {
				i++;
			}
			while (!isAlphaNumber(s.charAt(j)) && i < j) {
				j--;
			}
			if (s.charAt(i) != s.charAt(j)) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
}
