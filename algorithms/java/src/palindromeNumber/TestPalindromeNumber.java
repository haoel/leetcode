package palindromeNumber;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 9. Palindrome Number
 */
public class TestPalindromeNumber {
	@Test
	public void test() {
		PalindromeNumber solution = new PalindromeNumber();
		boolean flag1 = solution.isPalindrome(1234567);
		Assert.assertTrue(!flag1);
		boolean flag2 = solution.isPalindrome(1234321);
		Assert.assertTrue(flag2);
		boolean flag3 = solution.isPalindrome(12344321);
		Assert.assertTrue(flag3);
	}
}
