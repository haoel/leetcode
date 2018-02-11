// Source : https://leetcode.com/problems/length-of-last-word/description/
// Author : Tianming Cao
// Date   : 2018-02-11

/**********************************************************************************
 * 
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * 
 * Example:
 * 
 *  Input: "Hello World"
 *  Output: 5
 * 
 **********************************************************************************/
package lengthOfLastWord;

public class LengthOfLastWord {

	public int lengthOfLastWord(String s) {
		// don't forget rangeCheck
		if (s == null || s.length() == 0) {
			return 0;
		}
		int len = s.length();
		int i = len - 1;
		while (i >= 0 && s.charAt(i) == ' ') {
			i--;
		}
		if (i == -1) {
			return 0;
		}
		int count = 0;
		while (i >= 0 && s.charAt(i) != ' ') {
			count++;
			i--;
		}
		return count;
	}

}
