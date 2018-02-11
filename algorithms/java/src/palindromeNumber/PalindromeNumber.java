// Source : https://oj.leetcode.com/problems/palindrome-number/
// Author : Tianming Cao
// Date   : 2018-02-11

/**********************************************************************************
 * 
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * Some hints:
 * Could negative integers be palindromes? (ie, -1)
 * 
 * If you are thinking of converting the integer to string, note the restriction of using extra space.
 * 
 * You could also try reversing an integer. 
 * However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. 
 * How would you handle such case?
 * 
 * There is a more generic way of solving this problem.
 * 
 **********************************************************************************/
package palindromeNumber;

public class PalindromeNumber {
	
	/**
	 * The simple way is :
	 * Reverse x to reverseX and judge whether reverseX is equal to x
	 * For example:
	 * x is 1234321, then reverseX is 1234321, they are equal, so 1234321 is palindrome
	 * x is 1234123, then reverseX is 3214321, they are not equal, so 1234123 is not palindrome
	 */
	public boolean isPalindrome(int x) {
		if (x < 0) {
			return false;
		}
		if (x < 10) {
			return true;
		}
		int n = x;
		int reverseX = 0;
		while (n > 0) {
			reverseX = 10 * reverseX + n % 10;
			n /= 10;
		}
		if (reverseX == x) {
			return true;
		} else {
			return false;
		}
	}
}
