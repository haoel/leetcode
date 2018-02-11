package powXn;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 50. Pow(x, n)
 */
public class TestPowXn {
	@Test
	public void test() {
		PowXn solution = new PowXn();
		Assert.assertTrue(solution.myPow01(3, 9) == 19683);
		Assert.assertTrue(solution.myPow02(3, 9) == 19683);
		Assert.assertTrue(solution.myPow01(2.10000, -3)-0.10798<0.0001);
		Assert.assertTrue(solution.myPow02(2.10000, -3)-0.10798<0.0001);
	}
}
