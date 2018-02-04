package minStack;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 155. Min Stack
 */
public class TestMinStack {
	@Test
	public void test() {
		MinStack minStack = new MinStack();
		minStack.push(3);
		minStack.push(4);
		minStack.push(1);
		minStack.push(2);
		Assert.assertTrue(minStack.getMin() == 1);
		minStack.pop();
		minStack.pop();
		Assert.assertTrue(minStack.getMin() == 3);
	}
}
