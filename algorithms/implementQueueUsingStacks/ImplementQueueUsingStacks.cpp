// Source : https://leetcode.com/problems/implement-queue-using-stacks/
// Author : Hao Chen
// Date   : 2015-07-16

/********************************************************************************** 
 * 
 * Implement the following operations of a queue using stacks.
 * 
 * push(x) -- Push element x to the back of queue.
 * 
 * pop() -- Removes the element from in front of queue.
 * 
 * peek() -- Get the front element.
 * 
 * empty() -- Return whether the queue is empty.
 * 
 * Notes:
 * 
 * You must use only standard operations of a stack -- which means only push to top, 
 * peek/pop from top, size, and is empty operations are valid.

 * Depending on your language, stack may not be supported natively. You may simulate a 
 * stack by using a list or deque (double-ended queue), as long as you use only 
 * standard operations of a stack.

 * You may assume that all operations are valid (for example, no pop or peek operations 
 * will be called on an empty queue).
 *               
 **********************************************************************************/

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        transfer(s1, s2);
        s2.pop();
        transfer(s2, s1);
    }

    // Get the front element.
    int peek(void) {
        transfer(s1, s2);
        int ret = s2.top();
        transfer(s2, s1);
        return ret;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty();
    }
private:
    stack<int> s1, s2;
    void transfer(stack<int>& s1, stack<int>& s2) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
};

