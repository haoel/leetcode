// Source : https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Hao Chen
// Date   : 2014-07-22

#include <stdio.h>

int binarySearch(int A[], int low, int high, int key){
    while(low<=high){
        int mid = low + (high - low)/2;
        if (key == A[mid]) return mid;
        if (key > A[mid]){
            low = mid + 1;
        }else {
            high = mid -1;
        }
    }
    return low;
}

double findMedianSortedArrayHelper(int A[], int m, int B[], int n, int lowA, int highA, int lowB, int highB) {

    int mid = lowA + (highA - lowA)/2;
    int pos = binarySearch(B, lowB, highB, A[mid]);
    int num = mid + pos;
    if (num == (m+n)/2){
        if ((m+n)%2==1){
            return A[mid];
        }
        int next;

        if (mid>0 && pos>0){ 
            next = A[mid-1]>B[pos-1] ? A[mid-1] : B[pos-1];
        }else if(pos>0){
            next = B[pos-1];
        }else if(mid>0){
            next = A[mid-1];
        }
        
        return (A[mid] + next)/2.0;
    }
    if (num < (m+n)/2){
        lowA = mid + 1;
        lowB = pos;
        if ( highA - lowA > highB - lowB ) {
            return findMedianSortedArrayHelper(A, m, B, n, lowA, highA, lowB, highB);
        }
        return findMedianSortedArrayHelper(B, n, A, m, lowB, highB, lowA, highA);
    }
    if (num > (m+n)/2) {
        highA = mid - 1;
        highB = pos-1;
        if ( highA - lowA > highB - lowB ) {
            return findMedianSortedArrayHelper(A, m, B, n, lowA, highA, lowB, highB);
        }
        return findMedianSortedArrayHelper(B, n, A, m, lowB, highB, lowA, highA);
    }

}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if ( m==0 && n==0 ) return 0.0;
    if ( m==0 ) return n%2==1 ? B[n/2] : (B[n/2-1] + B[n/2])/2.0;
    if ( n==0 ) return m%2==1 ? A[m/2] : (A[m/2-1] + A[m/2])/2.0;
    
    
    if ( m > n ){
        return findMedianSortedArrayHelper(A, m, B, n, 0, m-1, 0, n-1);
    }
        
    return findMedianSortedArrayHelper(B, n, A, m, 0, n-1, 0, m-1);
}


int main()
{
    int r1[] = {1};
    int r2[] = {2};
 
    int n1 = sizeof(r1)/sizeof(r1[0]);
    int n2 = sizeof(r2)/sizeof(r2[0]);

    printf("Median is 1.5 = %f\n", findMedianSortedArrays(r1, n1, r2, n2));

    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45, 50};
 
    n1 = sizeof(ar1)/sizeof(ar1[0]);
    n2 = sizeof(ar2)/sizeof(ar2[0]);

    printf("Median is 17 = %f\n", findMedianSortedArrays(ar1, n1, ar2, n2));

    int ar11[] = {1, 12, 15, 26, 38};
    int ar21[] = {2, 13, 17, 30, 45 };
 
    n1 = sizeof(ar11)/sizeof(ar11[0]);
    n2 = sizeof(ar21)/sizeof(ar21[0]);

    printf("Median is 16 = %f\n", findMedianSortedArrays(ar11, n1, ar21, n2));

    int a1[] = {1, 2, 5, 6, 8 };
    int a2[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a1)/sizeof(a1[0]);
    n2 = sizeof(a2)/sizeof(a2[0]);

    printf("Median is 10.5 = %f\n", findMedianSortedArrays(a1, n1, a2, n2));

    int a10[] = {1, 2, 5, 6, 8, 9, 10 };
    int a20[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a10)/sizeof(a10[0]);
    n2 = sizeof(a20)/sizeof(a20[0]);

    printf("Median is 9.5 = %f\n", findMedianSortedArrays(a10, n1, a20, n2));

    int a11[] = {1, 2, 5, 6, 8, 9 };
    int a21[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a11)/sizeof(a11[0]);
    n2 = sizeof(a21)/sizeof(a21[0]);

    printf("Median is 9 = %f\n", findMedianSortedArrays(a11, n1, a21, n2));

    int a12[] = {1, 2, 5, 6, 8 };
    int a22[] = {11, 13, 17, 30, 45, 50};
 
    n1 = sizeof(a12)/sizeof(a12[0]);
    n2 = sizeof(a22)/sizeof(a22[0]);

    printf("Median is 11 = %f\n", findMedianSortedArrays(a12, n1, a22, n2));

    int b1[] = {1 };
    int b2[] = {2,3,4};
 
    n1 = sizeof(b1)/sizeof(b1[0]);
    n2 = sizeof(b2)/sizeof(b2[0]);

    printf("Median is 2.5 = %f\n", findMedianSortedArrays(b1, n1, b2, n2));
    return 0;
}
