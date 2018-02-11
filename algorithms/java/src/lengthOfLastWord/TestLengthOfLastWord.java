package lengthOfLastWord;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 58. Length of Last Word
 */
public class TestLengthOfLastWord {
	@Test
	public void test() {
		LengthOfLastWord solution = new LengthOfLastWord();
		String str1 = "Hello World";
		Assert.assertTrue(solution.lengthOfLastWord(str1) == 5);
		String str2 = "Thank you very much  ";
		Assert.assertTrue(solution.lengthOfLastWord(str2) == 4);
	}
}
