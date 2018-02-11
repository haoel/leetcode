package countAndSay;

import org.junit.Assert;
import org.junit.Test;
/**
 * Test for 38. Count and Say
 */
public class TestCountAndSay {
	@Test
	public void test() {
		CountAndSay solution = new CountAndSay();
		String next5 = solution.countAndSay(5);
		Assert.assertTrue(next5.equals("111221"));
		String next6 = solution.countAndSay(6);
		Assert.assertTrue(next6.equals("312211"));
	}
}
