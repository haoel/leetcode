// Source : https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
// Author : Hao Chen
// Date   : 2014-07-20

/********************************************************************************** 
* 
* Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
* 
* Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
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

int largestRectangleArea(vector<int> &height) {
    if (height.size()<=0) return 0;
    vector<int> stack;
    height.push_back(0);
    int maxArea = 0;
    for(int i=0; i<height.size(); i++){
        if ( stack.size()<=0 || height[i] >= height[stack.back()] ) {
            stack.push_back(i);
            continue;
        }
        int topIdx = stack.back();
        stack.pop_back();
        int area = height[topIdx] * (stack.size()==0 ? i : i - stack.back() - 1 );
        if ( area > maxArea ) {
            maxArea = area;
        }
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
