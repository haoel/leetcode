// Source : https://oj.leetcode.com/problems/sort-colors/
// Author : Hao Chen
// Date   : 2014-06-25

/********************************************************************************** 
* 
* Given an array with n objects colored red, white or blue, sort them so that objects of 
* the same color are adjacent, with the colors in the order red, white and blue.
* 
* Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
* 
* Note:
* You are not suppose to use the library's sort function for this problem.
* 
* Follow up:
*  > A rather straight forward solution is a two-pass algorithm using counting sort.
*  > First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array 
*    with total number of 0's, then 1's and followed by 2's.
*  > Could you come up with an one-pass algorithm using only constant space?
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int*a, int*b)
{
    int t;
    t=*a;
    *a = *b;
    *b = t;
}
void sortColors(int a[], int n) {
    int zero=0, two=n-1;
    for(int i=0; i<=two; i++ ){
        if (a[i]==0){
            swap(&a[zero], &a[i]);
            zero++;
        }
        if (a[i]==2){
            swap(&a[two], &a[i]);
            two--; 
            i--;
        }
    }
    
}

void printArray(int a[], int n) {
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char** argv)
{
    int n = 7;
    if (argc>1)
        n = atoi(argv[1]);

    srand(time(NULL));

    int *a = new int[n];
    for (int i=0; i<n; i++){
        a[i] = random()%3;
    }
    printArray(a, n);
    sortColors(a, n);
    printArray(a, n);

    delete[] a;
}

