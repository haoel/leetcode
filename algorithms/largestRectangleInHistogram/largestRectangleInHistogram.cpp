// Source : https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
// Author : Hao Chen
// Date   : 2014-07-20

/********************************************************************************** 
 * 
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
 * find the area of largest rectangle in the histogram.
 * 
 *                    6          
 *                  +---+        
 *               5  |   |        
 *              +---+   |        
 *              |   |   |        
 *              |   |   |        
 *              |   |   |     3  
 *              |   |   |   +---+
 *        2     |   |   | 2 |   |
 *      +---+   |   |   +---+   |
 *      |   | 1 |   |   |   |   |
 *      |   +---+   |   |   |   |
 *      |   |   |   |   |   |   |
 *      +---+---+---+---+---+---+
 *      
 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 *      
 *      
 *                    6          
 *                  +---+        
 *               5  |   |        
 *              +-------|        
 *              |-------|        
 *              |-------|        
 *              |-------|     3  
 *              |-------|   +---+
 *        2     |-------| 2 |   |
 *      +---+   |-------|---+   |
 *      |   | 1 |-------|   |   |
 *      |   +---|-------|   |   |
 *      |   |   |-------|   |   |
 *      +---+---+---+---+---+---+
 *      
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 * 
 * For example,
 * Given height = [2,1,5,6,2,3],
 * return 10.
 * 
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// As we know, the area = width * height
// For every bar, the 'height' is determined by the loweset bar.
//
// 1) We traverse all bars from left to right, maintain a stack of bars. Every bar is pushed to stack once. 
// 2) A bar is popped from stack when a bar of smaller height is seen. 
// 3) When a bar is popped, we calculate the area with the popped bar as smallest bar. 
// 4) How do we get left and right indexes of the popped bar – 
//    the current index tells us the ‘right index’ and index of previous item in stack is the ‘left index’. 
//
//
// In other word, the stack only stores the incresing bars, let's see some example  
//
// Example 1
// ---------
// height = [1,2,3,4]
//
//    stack[] = [ 0, 1, 2, 3 ], i=4
//
//    1) pop 3,  area = height[3] * 1 = 4
//    2) pop 2,  area = height[2] * 2 = 4
//    3) pop 1,  area = height[1] * 3 = 6
//    4) pop 0,  area = height[0] * 4 = 4
//
//
// Example 2
// ---------
// height = [2,1,2]
//
//    stack[] = [ 0 ], i=1
//    1) pop 0,  area = height[0] * 1 = 2
//
//    stack[] = [ 1,2 ], i=3, meet the end
//    1) pop 2,  area = height[2] * 1 = 2
//    2) pop 1,  area = height[1] * 3 = 3
//
//
// Example 3
// ---------
// height =  [4,2,0,3,2,5]  
//
//    stack[] = [ 0 ], i=1, height[1] goes down
//    1) pop 0,  area = height[0] * 1 = 4
//
//    stack[] = [ 1 ], i=2, height[2] goes down
//    1) pop 1,  area = height[1] * 2 = 4 // <- how do we know the left?
//                                              start from the 0 ?? 
//
//    stack[] = [ 2, 3 ], i=4, height[4] goes down
//    1) pop 3,  area = height[3] * 1 = 3
//    2) pop 2,  area = height[2] * ? = 0 // <- how do we know the left? 
//                                              start from the 0 ??
//
//    stack[] = [ 2,4,5 ], i=6,  meet the end
//    1) pop 5,  area = height[5] * 1 = 5
//    2) pop 4,  area = height[4] * 3 = 6 // <- how do we know the left?
//                                              need check the previous item.
//    3) pop 2,  area = height[2] * ? = 4 // <- how do we know the left?
//                                              start from the 0 ??
//
//    so, we can see, when the stack pop the top, the area formular is 
//
//          height[stack_pop] *  i - stack[current_top] - 1,   if stack is not empty
//          height[stack_pop] *  i,                            if stack is empty
//
int largestRectangleArea(vector<int> &height) {
    if (height.size()<=0) return 0;
    //Create an empty stack.
    vector<int> stack;
    //add a flag as a trigger if the end bar is met, and need to check the stack is empty of not .
    height.push_back(0);
    int maxArea = 0;
    for(int i=0; i<height.size(); i++){
        //If stack is empty or height[i] is higher than the bar at top of stack, then push ‘i’ to stack.
        if ( stack.size()<=0 || height[i] >= height[stack.back()] ) {
            stack.push_back(i);
            continue;
        }
        //If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. 
        //Let the removed bar be height[top]. Calculate area of rectangle with height[top] as smallest bar. 
        //For height[top], the ‘left index’ is previous (previous to top) item in stack and ‘right index’ is ‘i’ (current index).
        int topIdx = stack.back();
        stack.pop_back();
        int area = height[topIdx] * (stack.size()==0 ? i : i - stack.back() - 1 );
        if ( area > maxArea ) {
            maxArea = area;
        }
        //one more time. Because the stack might still have item.
        i--;
    }

    return maxArea;
}

void printArray(vector<int> &v)
{
    cout << "{";
    for(int i=0; i<v.size(); i++) {
        cout << " " << v[i];
    }
    cout << "}" << endl;
}
void test(int a[], int n)
{
    vector<int> v(a, a + n);
    printArray(v);
    cout << largestRectangleArea(v) << endl;
}

int main()
{
#define TEST(a) test(a, sizeof(a)/sizeof(int))

    int a0[] = {2,1,3,1};
    TEST(a0);
    int a1[] = {2,1,5,6,2,3};
    TEST(a1);

    return 0;
}

/*int main()
{
    int a[] = {2,1,5,6,2,3};
    vector<int> v(a, a + sizeof(a)/sizeof(int));
    printArray(v);
    cout << largestRectangleArea(v) << endl;
    return 0;
}*/
