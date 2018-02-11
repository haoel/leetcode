package strStr;

import org.junit.Assert;
import org.junit.Test;
/**
 * Test for 28. Implement strStr() using KMP-Algorithm
 */
public class TestStrStrKmp {
	@Test
	public void testKmp() {
		StrStrKmp solution = new StrStrKmp();
		String hayStack1 = "aabbccagdbbccdec";
		String needle1 = "bbccd";
		int result1 = solution.strStr(hayStack1, needle1);
		Assert.assertTrue(result1 == 9);
		String hayStack2 = "aabbccagdbbccdec";
		String needle2 = "bbccf";
		int result2 = solution.strStr(hayStack2, needle2);
		Assert.assertTrue(result2 == -1);
		String hayStack3 = "BBC ABCDAB ABCDABCDABDE";
		String needle3 = "ABCDABD";
		int result3 = solution.strStr(hayStack3, needle3);
		Assert.assertTrue(result3 == 15);
	}
}
