// Source : https://oj.leetcode.com/problems/maximum-product-subarray/
// Author : Hao Chen
// Date   : 2014-10-09

/********************************************************************************** 
* 
* Find the contiguous subarray within an array (containing at least one number) 
* which has the largest product.
* 
* For example, given the array [2,3,-2,4],
* the contiguous subarray [2,3] has the largest product = 6.
* 
* More examples:
*   
*   Input: arr[] = {6, -3, -10, 0, 2}
*   Output:   180  // The subarray is {6, -3, -10}
*   
*   Input: arr[] = {-1, -3, -10, 0, 60}
*   Output:   60  // The subarray is {60}
*   
*   Input: arr[] = {-2, -3, 0, -2, -40}
*   Output:   80  // The subarray is {-2, -40}
*               
**********************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

// The idea is similar with "Find the subarray wich has the largest sum"
// (See: http://en.wikipedia.org/wiki/Maximum_subarray_problem)
// 
// The only thing to note here is, maximum product can also be obtained by minimum (negative) product 
// ending with the previous element multiplied by this element. For example, in array {12, 2, -3, -5, -6, -2}, 
// when we are at element -2, the maximum product is multiplication of, minimum product ending with -6 and -2.
//
int maxProduct(int A[], int n) {

    // To remember the max/min product for previous position
    int maxPrev = A[0], minPrev = A[0];
    // To remember the max/min product for current position
    int maxHere = A[0], minHere = A[0];
    // Overall maximum product
    int maxProd = A[0];

    for (int i=1; i<n; i++){
        //max( maxPrev * A[i],  minPrev * A[i],  A[i] )
        maxHere = max( max( maxPrev * A[i], minPrev * A[i] ), A[i] );
        //min( maxPrev * A[i],  minPrev * A[i],  A[i] )
        minHere = min( min( maxPrev * A[i], minPrev * A[i] ), A[i] );
        //Keep tracking the overall maximum product
        maxProd = max(maxHere, maxProd);
        //Shift the current max/min product to previous variables
        maxPrev = maxHere;
        minPrev = minHere;
    }
    return maxProd;    
}


#define TEST(a)    cout << maxProduct( a, sizeof(a)/sizeof(int)) << endl
int main()
{
    int o[] = {2,3,-2,4};
    TEST(o);

    int a[] = {-4,-3};
    TEST(a);

    int b[] = {-1, -1};
    TEST(b);

    int c[] = {-1, 0, -2};
    TEST(c);
}
