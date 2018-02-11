// Source : https://leetcode.com/problems/count-and-say/description/
// Author : Tianming Cao
// Date   : 2018-02-11

/**********************************************************************************
 * 
 * The count-and-say sequence is the sequence of integers with the first five terms as following:
 * 
 *  1.     1
 *  2.     11
 *  3.     21
 *  4.     1211
 *  5.     111221
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth term of the count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a string.
 * 
 * Example 1:
 * 
 *  Input: 1
 *  Output: "1"
 * 
 * Example 2:
 * 
 *  Input: 4
 *  Output: "1211"
 * 
 **********************************************************************************/
package countAndSay;

public class CountAndSay {

	public String nextString(String str) {
		StringBuilder next = new StringBuilder();
		int len = str.length();
		int i = 0;
		while (i < len) {
			int j = i;
			int count = 0;
			char currentNumber = str.charAt(i);
			while (j < len && str.charAt(j) == currentNumber) {
				j++;
				count++;
			}
			next.append(count).append(currentNumber);
			i = j;
		}
		return next.toString();
	}
	public String countAndSay(int n) {
		if (n <= 1) {
			return "1";
		} else {
			String p = "1";
			for (int i = 2; i <= n; i++) {
				String next = nextString(p);
				p = next;
			}
			return p;
		}
	}

}
