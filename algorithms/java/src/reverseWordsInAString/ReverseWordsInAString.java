// Source : https://leetcode.com/problems/reverse-words-in-a-string/description/
// Author : Tianming Cao
// Date   : 2018-02-11

/**********************************************************************************
 * 
 * Given an input string, reverse the string word by word.
 * 
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 * 
 * Update (2015-02-12):
 * For C programmers: Try to solve it in-place in O(1) space.
 * 
 **********************************************************************************/
package reverseWordsInAString;

public class ReverseWordsInAString {

	public String reverseWords(String s) {
		if (s == null || s.length() == 0) {
			return s;
		}
		s = s.trim();
		String[] array = s.split("\\s+");
		StringBuilder sb = new StringBuilder();
		int len = array.length;
		for (int i = len - 1; i > 0; i--) {
			sb.append(array[i]).append(" ");
		}
		sb.append(array[0]);
		return sb.toString();
	}
}
