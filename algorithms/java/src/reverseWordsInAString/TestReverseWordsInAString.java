package reverseWordsInAString;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 151. Reverse Words in a String
 */
public class TestReverseWordsInAString {
	@Test
	public void test() {
		ReverseWordsInAString solution = new ReverseWordsInAString();
		String str = " the    sky is   blue   ";
		String result = solution.reverseWords(str);
		Assert.assertTrue(result.equals("blue is sky the"));
	}
}
