// Source : https://oj.leetcode.com/problems/single-number/
// Author : Hao Chen
// Date   : 2014-06-17

/********************************************************************************** 
* 
* Given an array of integers, every element appears twice except for one. Find that single one.
* 
* Note:
* Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
* 
*               
**********************************************************************************/

#include <stdio.h>
// This is classical interview question
// As we know, the same number XOR together will be 0,
// So, XOR all of numbers, the result is the number which only appears once. 
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
