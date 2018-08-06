package validPalindrome;

import org.junit.Assert;
import org.junit.Test;
/**
 * Test for 125. Valid Palindrome
 */
public class TestValidPalindrome {
	@Test
	public void test() {
		ValidPalindrome solution = new ValidPalindrome();
		String str1 = "A man, a plan, a canal: Panama";
		Assert.assertTrue(solution.isPalindrome(str1));
		String str2 = "race a car";
		Assert.assertTrue(!solution.isPalindrome(str2));
	}
}
