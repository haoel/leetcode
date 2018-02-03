// Source : https://leetcode.com/problems/implement-stack-using-queues/description/
// Author : Tianming Cao
// Date   : 2018-02-02

/**********************************************************************************
 * Implement the following operations of a stack using queues.

 * 	push(x) -- Push element x onto stack.
 * 	pop() -- Removes the element on top of the stack.
 * 	top() -- Get the top element.
 * 	empty() -- Return whether the stack is empty.
 * Notes:
 * 	You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 *  Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 *  You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 *
 **********************************************************************************/
package myStack;

import java.util.LinkedList;
import java.util.Queue;
/**********************************************************************************
 * This problem is a sibling of problem 232(https://leetcode.com/problems/implement-queue-using-stacks/description/).
 * The train of thought is:
 *	If we want to pop a element,first we should judge which queue is not empty assumed queue1,another empty queue assumed queue2.
 *	Next,we pop all element from queue1 and push them into queue2 util queue1's size is 1.
 *	Finally the last element in queue1 is the correct pop value.
 *	If queue1 is empty and queue2 is not empty,the step is symmetric.
 *	The top operation is similar with pop operation.
 **********************************************************************************/
public class MyStack {
	public Queue<Integer> queue1;
	public Queue<Integer> queue2;
	public int flag;
	public int size;
	    public MyStack() {
	        queue1=new LinkedList<Integer>();
	        queue2=new LinkedList<Integer>();
	        flag=1;
	        size=0;
	    }
	    
	    public void push(int x) {
	        if(flag==1){
	        	queue1.offer(x);
	        }else{
	        	queue2.offer(x);
	        }
	        size++;
	    }
	    
	    public int pop() {
	    	int value;
	        if(flag==1){
	        	while(queue1.size()>1){
	        		queue2.offer(queue1.poll());
	        	}
	        	value=queue1.poll();
	        	flag=2;
	        }else{
	        	while(queue2.size()>1){
	        		queue1.offer(queue2.poll());
	        	}
	        	value=queue2.poll();
	        	flag=1;
	        }
	        size--;
	        return value;
	    }
	    
	    public int top() {
	    	if(flag==1){
	        	while(queue1.size()>1){
	        		queue2.offer(queue1.poll());
	        	}
	        	int value=queue1.poll();
	        	queue2.offer(value);
	        	flag=2;
	        	return value;
	        }else{
	        	while(queue2.size()>1){
	        		queue1.offer(queue2.poll());
	        	}
	        	int value=queue2.poll();
	        	queue1.offer(value);
	        	flag=1;
	        	return value;
	        }
	    }
	    
	    public boolean empty() {
	        return size==0?true:false;
	    }
}
