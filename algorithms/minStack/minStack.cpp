// Source : https://oj.leetcode.com/problems/min-stack/
// Author : Hao Chen
// Date   : 2014-11-16

/********************************************************************************** 
* 
* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
* 
* push(x) -- Push element x onto stack.
* 
* pop() -- Removes the element on top of the stack.
* 
* top() -- Get the top element.
* 
* getMin() -- Retrieve the minimum element in the stack.
* 
*               
**********************************************************************************/

#include <stdlib.h>
#include <iostream>
using namespace std;

//It seems C++ vector cause the Memory Limit Error, So, implement a simple one
template <typename T>
class Stack {
    private:
        T* _stack;
        int _capacity;
        int _top;
    public:
        Stack():_capacity(1),_top(-1){
            _stack = (T*)malloc(_capacity*sizeof(T));
        }

        ~Stack(){
            free(_stack);
        }

        void push(T x){
            _top++;
            if ( _top >= _capacity ){
                //if capacity is not enough, enlarge it 5 times.
                //Notes: why 5 times? because if you change to other(e.g. 2 times), 
                //       LeetCode system will report Run-time Error! it sucks!
                _capacity*=5;
                _stack = (T*)realloc(_stack, _capacity*sizeof(T));
            }
            _stack[_top] = x;
        }

        T pop() {
            return top(true);
        }

        T& top(bool pop=false) {
            if (_top>=0){
                if (pop){
                    return _stack[_top--];
                }
                return _stack[_top];
            }
            static T null;
            return null;
        }

        bool empty(){
            return (_top<0);
        }
        int size() {
            return _top+1;
        }
        void clear(){
            _top = -1;
        }
};


/*
 * Idea: 
 *
 *    Using two stacks, 
 *    1) one stack is the real stack to store the data.
 *    2) another stack store the minimal number when it changes.
 *
 *    For example:
 *
 *        if we keep pushing the following numbers:
 *        5 1 1 2 3 2 
 *        the minial number stack will be: 
 *        5 1 1   <-- only store the number which <= cureent minimal number
 *   
 *    Then, when we pop up the stack.
 *
 *    we need compare whether the current number is the current minial number.
 *    if it is, then we need popup the number in minimal number stack.
 *        
 */
class MinStack {
    private:
        //Using a minData struct to remove the duplication in minimal stack
        //which can save the memory.
        struct minData{
            int min;
            int cnt;
            minData():min(0), cnt(0) {}
            minData(int m, int c):min(m),cnt(c){}
        };
        Stack<int> stack; //real stack store the data
        Stack<minData> minStack; //minimal number stack store the number 
        int min; //current minial number

    public:

        void push(int x) {
            if(stack.empty()){
                min = x;
                minStack.push(minData(x,1));
            }else{
                if (min >= x ){
                    min = x;
                    //if current minial number already pushed, then just add the reference coount.
                    if (minStack.top().min == x){
                        minStack.top().cnt++;
                    }else{
                        minStack.push(minData(x,1));
                    }
                }
            }
            stack.push(x);

        }

        void pop() {
            if (stack.empty()){
                return;
            }
            int x = stack.pop();
            if (x == minStack.top().min){
                //de-reference the count at first.
                if (minStack.top().cnt > 1){
                    minStack.top().cnt--;
                }else{
                    minStack.pop();
                    min = minStack.top().min;
                }
            }
        }

        int top() {
            return stack.top();
        }

        int getMin() {
            return min;
        }
        void clear() {
            stack.clear();
            minStack.clear();
        }

};

int main()
{
    cout << "--- expected output [0, 0, 0, 2]" << endl;
    MinStack ms;
    ms.push(2);
    ms.push(0);
    ms.push(3);
    ms.push(0);

    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;


    ms.clear();

    cout << "--- expected output [2147483647 2147483646 2147483646 2147483647 2147483647 -2147483648 -2147483648 2147483647 " << endl;

    ms.push(2147483646);
    ms.push(2147483646);
    ms.push(2147483647);

    cout << ms.top() << endl;
    ms.pop();
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;
    ms.pop();

    ms.push(2147483647);
    cout << ms.top() << endl;
    cout << ms.getMin() << endl;
    ms.push(-2147483648);
    cout << ms.top() << endl;
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;


    return 0;
}
