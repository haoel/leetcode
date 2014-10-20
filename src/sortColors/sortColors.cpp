// Source : https://oj.leetcode.com/problems/sort-colors/
// Author : Hao Chen
// Date   : 2014-06-25

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

