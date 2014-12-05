// Source : https://oj.leetcode.com/problems/find-peak-element/
// Author : Hao Chen
// Date   : 2014-12-05

/********************************************************************************** 
* 
* A peak element is an element that is greater than its neighbors.
* 
* Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
* 
* You may imagine that num[-1] = num[n] = -∞.
* 
* For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
* 
* click to show spoilers.
* 
* Note:
* Your solution should be in logarithmic complexity.
* 
* Credits:Special thanks to @ts for adding this problem and creating all test cases.
*               
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;



/*
 *    Binary search is common idea here.
 *
 *    However, you need to think about two senarios:
 *
 *    1) Becasue we need check `num[mid-1]`, `num[mid]`, `num[mid+1]`, 
 *       So, we need make sure there hasn't out-of-boundary issue.
 *   
 *
 *
 *    2) There are multiple Peak elements.
 *
 *       For example: [1,2,1,2,1], or [ 1,2,3,1,2,1]
 *
 *       LeetCode doesn't tell you what the expected result is. I guess:
 *
 *       2.1) for [1,2,1,2,1] you can return either 1 or 3, because both them are peak elements
 *
 *       2.1) for [1,2,3,2,4,2,1] it should return 4, because num[4] is the real peak.  but Leetcode accept either 2 or 4
 *
 */

int findPeakElement(const vector<int> &num) {

    int n = num.size();
    int low = 0;
    int high = n - 1;

    int mid = 0, v1, v2;

    while ( low < high ) {

        // Find the index of middle element
        mid = low + ( high - low ) / 2;

        // Compare middle element with its neighbours (if neighbours exist)
        if ( ( mid == 0 || num[mid] > num[mid-1] ) && 
                ( mid == n-1 ||  num[mid] > num[mid+1] )  ){
            return mid;
        }

        // If middle element is not peak and its left neighbor is greater than it
        // then left half must have a peak element
        if (mid >0 && num[mid-1] > num[mid]){
            high = mid - 1;
        // If middle element is not peak and its right neighbor is greater than it
        // then right half must have a peak element
        }else{
            low = mid + 1;
        }

    }

    return low;
}


void printVector(vector<int> &n) {
    cout << "[ ";
    int i;
    for(i=0; i<n.size(); i++){
        cout << n[i] << (i==n.size()-1 ? " ]" : ", ");
    }
    cout << endl;
}

void test(int a[], int n) {
    vector<int> v(a, a+n);
    cout << "Peak Index = " << findPeakElement(v) << "\t";
    printVector(v);
}


#define TEST(a) test(a, sizeof(a)/sizeof(a[0]))

int main(int argc, char**argv)
{
    int n0[] = {1};
    TEST(n0);

    int n1[] = {1,2};
    TEST(n1);

    int n2[] = {2,1};
    TEST(n2);

    int n3[] = {1,2,3};
    TEST(n3);

    int n4[] = {3,2,1};
    TEST(n4);

    int n5[] = {1,2,3,2};
    TEST(n5);

    int n6[] = {0,1,2,9,7,5,4,2,1};
    TEST(n6);

    int n7[] = {1,2,1,2,1};
    TEST(n7);

    int n8[] = {1,2,1,2,3,1};
    TEST(n8);

    int n9[] = {1,2,3,2,4,2,1};
    TEST(n9);

    int n10[] = {1,3,1,2,1,3,1};
    TEST(n10);

    return 0;
}
