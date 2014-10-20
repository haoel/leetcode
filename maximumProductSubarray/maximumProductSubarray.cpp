// Source : https://oj.leetcode.com/problems/maximum-product-subarray/
// Author : Hao Chen
// Date   : 2014-10-09

#include <iostream>
#include <algorithm>
using namespace std;

int maxProduct(int A[], int n) {

    int maxHere = A[0], minHere = A[0];
    int maxProd = A[0];
    int maxPrev = A[0], minPrev = A[0];

    for (int i=1; i<n; i++){
        maxHere = max( max( maxPrev * A[i], minPrev * A[i] ), A[i] );
        minHere = min( min( maxPrev * A[i], minPrev * A[i] ), A[i] );
        maxProd = max(maxHere, maxProd);
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
}
