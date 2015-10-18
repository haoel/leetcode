// Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Author : Hao Chen
// Date   : 2014-06-29

/********************************************************************************** 
* 
* Follow up for "Remove Duplicates":
* What if duplicates are allowed at most twice?
* 
* For example,
* Given sorted array A = [1,1,1,2,2,3],
* 
* Your function should return length = 5, and A is now [1,1,2,2,3].
* 
*               
**********************************************************************************/

#include <stdio.h>


int removeDuplicates(int A[], int n) {
    if (n<=2) return n;
    int pos=0;
    int cnt=1;
    for (int i=1; i<n; i++){
        if (A[i] == A[pos]){
            cnt++;
            if (cnt==2){
                A[++pos] = A[i];
            }
        }else{
            cnt=1;
            A[++pos] = A[i];
            
        }
    } 
    return pos+1;
}

void printfArray(int A[], int n) {
    printf("{ ");
    for (int i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("}\n");
}


void testSuite(int a[], int n){
    printfArray(a, n);
    n = removeDuplicates(a, n);
    printfArray(a, n);
    printf("------------------\n");
}

#define TEST(a) testSuite(a, sizeof(a)/sizeof(int))
int main()
{
    int a0[] = {1, 2, 3, 4, 5};
    TEST(a0);
    int a1[] = {1, 1, 1};
    TEST(a1);
    int a2[] = {1, 2, 2};
    TEST(a2);
    int a3[] = {1, 1, 2};
    TEST(a3);
    int a4[] = {1, 1, 1, 1};
    TEST(a4);
    int a5[] = {1, 1, 1, 2};
    TEST(a5);
    int a6[] = {1, 2, 2, 2};
    TEST(a6);
    int a7[] = {1, 2, 2, 2, 3 };
    TEST(a7);
    int a8[] = {1, 2, 2, 2, 3, 3};
    TEST(a8);
    int a9[] = {1,1,1,2,2,3};
    TEST(a9);
    int a10[] = {1,1,1,2,2,2};
    TEST(a10);
    int a11[] = {1,1,1,1,3,3};
    TEST(a11);
    return 0;
}
