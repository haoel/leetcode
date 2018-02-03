package myStack;

import org.junit.Assert;
import org.junit.Test;
/**
 * Test for 225. Implement Stack using Queues
 */
public class TestMyStack {
@Test
public void test(){
	MyStack stack=new MyStack();
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	Assert.assertTrue(stack.empty()==false);
	Assert.assertTrue(stack.pop()==4);
	Assert.assertTrue(stack.pop()==3);
	Assert.assertTrue(stack.top()==2);
	stack.push(5);
	Assert.assertTrue(stack.top()==5);
}
}
