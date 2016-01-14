// Source : https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Author : Hao Chen
// Date   : 2014-10-20

/********************************************************************************** 
* 
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
* 
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* 
* Find the minimum element.
* 
* You may assume no duplicate exists in the array.
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

/* 
 *  Obveriously, to search any sorted array, the binary search is the common sense.
 * 
 *  To solve this problem, the idea is same as the search in rotated sorted array.
 */
int findMin(vector<int> &num) {

    int low=0, high=num.size()-1;

    while(high-low>1){
        int mid = low + (high-low)/2;
        // Chek the array if it is non-rotated, then just return the first element.
        if (num[low] < num[mid] && num[mid] < num[high]){
            return num[low];
        }

        // The array is rotated
        // Split it into two part, the minimal value must be the rotated part
        
        // if the left part is rotated, warch the left part
        if (num[low] > num [mid]){
            high = mid;
            continue;
        }
        // if the right part is rotated, search the right part.
        if (num[mid] > num[high]){
            low = mid;
            continue;
        }
    }
    // the array only has 1 element
    if (high == low) return num[low];

    // the array has 2 elements
    return num[low] < num[high] ? num[low] : num[high];

}


void rotate_array(int a[], int n, int pos){
    int i, from=0;
    pos = pos % n;
    if (n<=0) return;

    int tmp = a[0];

    for(int i=0, step=0; step<n && i<pos; step++){
        int to;
        if (from-pos < 0) {
            to = n-pos+from; 
        }else{
            to = from-pos;
        }
        int t ;
        t = a[to];
        a[to] = tmp; 
        tmp = t;
        from = to;
        if ( to == i ){
            i++;
            from++;
            tmp = a[from];
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

int main(int argc, char** argv)
{

    int cnt=20;

    if (argc>1) {
        cnt = atoi(argv[1]);
    }

    srand(time(NULL)); 

    int expectedMin, actualMin;
    int *a = new int[cnt];
    for(int n=0; n<=cnt; n++) {
        printf("--------------------------------------\n");
        for(int i=0; i<cnt; i++){
            a[i]=i;
        }
        expectedMin = a[0];
        //printArray(a, cnt);
        int rotate_pos = random() % cnt;
        //rotate_pos=2;
        printf("rotate=%d\n", rotate_pos);
        rotate_array(a, cnt, rotate_pos);
        printArray(a, cnt);

        vector<int> num(a, a+cnt);
        actualMin = findMin(num);
        cout << "findMin = " << actualMin << "   " << (expectedMin==actualMin ? "passed" : "failed") << endl;

    }
    delete[] a;

    return 0;
}
