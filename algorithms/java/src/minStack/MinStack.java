// Source : https://leetcode.com/problems/min-stack/description/
// Author : Tianming Cao
// Date   : 2018-02-02

/**********************************************************************************
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 *	push(x) -- Push element x onto stack.
 *	pop() -- Removes the element on top of the stack.
 *	top() -- Get the top element.
 *	getMin() -- Retrieve the minimum element in the stack.
 * Example:
 *	MinStack minStack = new MinStack();
 *	minStack.push(-2);
 *	minStack.push(0);
 *	minStack.push(-3);
 *	minStack.getMin();   --> Returns -3.
 *	minStack.pop();
 *	minStack.top();      --> Returns 0.
 *	minStack.getMin();   --> Returns -2.
 * 
 **********************************************************************************/
package minStack;

import java.util.Stack;

public class MinStack {
	public Stack<Integer> mainStack;
	/**
	 * Call an extra stack named assistStack to store the min value.
	 * While we doing push operation, compare x with the top of assistStack and push the smaller value into assistStack.
	 * The other operations pop,top and getMin is very simple.
	 **/
	public Stack<Integer> assistStack;
	public MinStack() {
		mainStack = new Stack<Integer>();
		assistStack = new Stack<Integer>();
	}
	public void push(int x) {
		mainStack.push(x);
		if (assistStack.isEmpty()) {
			assistStack.push(x);
		} else {
			assistStack.push(Math.min(x, getMin()));
		}
	}

	public void pop() {
		mainStack.pop();
		assistStack.pop();
	}

	public int top() {
		return mainStack.peek();
	}

	public int getMin() {
		return assistStack.peek();
	}
}
