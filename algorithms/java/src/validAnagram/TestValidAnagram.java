package validAnagram;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 242. Valid Anagram
 */
public class TestValidAnagram {
	@Test
	public void test() {
		ValidAnagram solution = new ValidAnagram();
		Assert.assertTrue(solution.isAnagram("anagram", "nagaram"));
		Assert.assertTrue(!solution.isAnagram("rat", "car"));
	}
}
