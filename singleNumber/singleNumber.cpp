// Source : https://oj.leetcode.com/problems/single-number/
// Author : Hao Chen
// Date   : 2014-06-17

#include <stdio.h>

int singleNumber(int A[], int n) {
    int s = 0;
    for(int i=0; i<n; i++){
        s = s^A[i];
    }
    return s;
}

int main()
{
    int a[]={1,1,2,2,3};
    printf("%d\n", singleNumber(a,5));
    return 0;
}
