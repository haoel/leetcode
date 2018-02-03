package myQueue;

import org.junit.Assert;
import org.junit.Test;
/**
 * Test for 232. Implement Queue using Stacks
 */
public class TestMyQueue {
	@Test
    public void test(){
    	MyQueue queue=new MyQueue();
    	Assert.assertTrue(queue.empty());
    	queue.push(1);
    	queue.push(2);
    	queue.push(3);
    	queue.push(4);
    	Assert.assertTrue(queue.pop()==1);
    	Assert.assertTrue(queue.pop()==2);
    	queue.push(5);
    	Assert.assertTrue(queue.peek()==3);
    	Assert.assertTrue(!queue.empty());
    }
}
