// Source : https://oj.leetcode.com/problems/merge-sorted-array/
// Author : Hao Chen
// Date   : 2014-06-20

/********************************************************************************** 
* 
* Given two sorted integer arrays A and B, merge B into A as one sorted array.
* 
* Note:
*   You may assume that A has enough space (size that is greater or equal to m + n) 
*   to hold additional elements from B. The number of elements initialized in A and B 
*   are m and n respectively.
*               
**********************************************************************************/

#include <stdio.h>

void merge(int A[], int m, int B[], int n) {
    int ia = m-1 ;
    int ib = n-1 ;
    int i = m + n - 1;
    for (int i=m+n-1; i>=0; i--){
        
        if (ia>=0 && ib<0){
            break;
        }
        if (ia<0 && ib>=0){
            A[i] = B[ib--];
            continue;
        }            
        if (ia>=0 && ib>=0){
            if (A[ia] > B[ib]){
                A[i] = A[ia--];
            }else{
                A[i] = B[ib--];
            }
        }

    }
}

void printArray(int A[], int n) {
    printf("{");
    for(int i=0; i<n; i++) {
        printf("%d, ", A[i]);
    }
    printf("}\n");
}

int main()
{
    int a[]={2,4,6,8,10,0,0,0};
    int b[]={1,3,5};
    merge(a, 5, b, 3 );
    printArray(a,  sizeof(a)/sizeof(int));

    int a1[]={2,4,0,0,0};
    int b1[]={3,5,7};
    merge(a1, 2, b1, 3 );
    printArray(a1, sizeof(a1)/sizeof(int));

    int a2[]={12,14,16,18,20,0,0,0};
    int b2[]={1,3,5};
    merge(a2, 5, b2, 3 );
    printArray(a2,  sizeof(a2)/sizeof(int));

    int a3[]={2,0};
    int b3[]={3,};
    merge(a3, 1, b3, 1 );
    printArray(a3, sizeof(a3)/sizeof(int));

    int a4[]={0,0,0};
    int b4[]={1,3,5};
    merge(a4, 0, b4, 3 );
    printArray(a4, sizeof(a4)/sizeof(int));

    int a5[]={2,4,6,8,10,0,0,0};
    int b5[]={11,13,15};
    merge(a5, 5, b5, 3 );
    printArray(a5,  sizeof(a5)/sizeof(int));

    int a6[]={2,4,0,0,0,0,0,0};
    int b6[]={1,3,5,7,9,11};
    merge(a6, 2, b6, 6 );
    printArray(a6, sizeof(a6)/sizeof(int));

    return 0;


}
