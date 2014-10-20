// Source : https://oj.leetcode.com/problems/search-insert-position/
// Author : Hao Chen
// Date   : 2014-06-22

#include <stdio.h>


int binary_search(int A[], int n, int key) {
    int low = 0;
    int high = n-1;
    while (low <= high){
        int mid = low +(high-low)/2;
        if (A[mid] == key){
            return mid;
        }
        if ( key> A[mid] ) {
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return low;
}
int searchInsert(int A[], int n, int target) {
    if (n==0) return n;
    return binary_search(A, n, target);
}

int main()
{
    int a[]={1,3,5,6};
    printf("%d -> %d\n", 5, searchInsert(a, 4, 5));
    printf("%d -> %d\n", 2, searchInsert(a, 4, 2));
    printf("%d -> %d\n", 7, searchInsert(a, 4, 7));
    printf("%d -> %d\n", 0, searchInsert(a, 4, 0));
    return 0;
}
