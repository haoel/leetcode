// Source : https://leetcode.com/problems/implement-queue-using-stacks/description/
// Author : Tianming Cao
// Date   : 2018-02-02

/**********************************************************************************
 * Implement the following operations of a queue using stacks.
 *
 * 	push(x) -- Push element x to the back of queue.
 *  pop() -- Removes the element from in front of queue.
 *  peek() -- Get the front element.
 *  empty() -- Return whether the queue is empty.
 *
 * Notes:
 *  You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
 *  Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
 *  You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
 *
 **********************************************************************************/
package myQueue;

import java.util.Stack;

/**
 * This problem is a sibling of problem 225(https://leetcode.com/problems/implement-stack-using-queues/description/)
 * The solution is:
 *	1. stack1 is always in charge of push operation
 *	2. stack2 is always in charge of peek and pop operation
 *	3. if we want to do peek or pop operation, but stack2 is empty,
 *     we should first pop all the elements from stack1 and push them into stack2 in turn.
 * Give a Example:
 * 
 *  First, push numbers "1,2,3,4,5" to stack1, then stack1's structure is:
 * 
 * |5|
 * |4|
 * |3|
 * |2|
 * |1|
 * 
 *	Second, if we want to get the front element "1",we should pop all the elements of stack1 and push them into stack2,
 *	after this, stack1 is empty, and stack2's structrue is:
 * 
 * |1|
 * |2|
 * |3|
 * |4|
 * |5|
 * 
 *	So we can get stack2's top element "1" as the front element of queue. 
 * 
 *	Next, if we want to push "6" to the back of queue, we should push "6" into stack1 as before, so stack1's structure is:
 * 
 * |6|
 * 
 *	Finally, if we want to do pop operation twice ,we should remove the top element of stack2 twice, so stack2's structure is:
 * 
 * |3|
 * |4|
 * |5|
 * 
 *	as expect, the removed element is "1" and "2".
 */
public class MyQueue {
	public Stack<Integer> stack1;
	public Stack<Integer> stack2;
	public int size;
	public MyQueue() {
		stack1 = new Stack<>();
		stack2 = new Stack<>();
		size = 0;
	}

	public void push(int x) {
		stack1.push(x);
		size++;
	}

	public int pop() {
		if (stack2.isEmpty()) {
			while (!stack1.isEmpty()) {
				stack2.push(stack1.pop());
			}
		}
		int value = stack2.pop();
		size--;
		return value;
	}

	public int peek() {
		if (stack2.isEmpty()) {
			while (!stack1.isEmpty()) {
				stack2.push(stack1.pop());
			}
		}
		return stack2.peek();
	}

	public boolean empty() {
		return size == 0 ? true : false;
	}
}
