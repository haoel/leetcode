// Source : https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
// Author : Hao Chen
// Date   : 2014-06-28

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int A[], int n, int key); 
int binary_search(int A[], int l, int h, int key); 
int rotate_search(int A[], int l, int h, int key);

int search1(int A[], int n, int target);
int search2(int A[], int n, int target); 

int search(int A[], int n, int target) {
    if (random()%2){
        return search1(A, n, target);
    }
    return search2(A, n, target);
}

int search1(int A[], int n, int key) {
    if (n<=0) return -1;

    if (n==1){
        return (A[0]==key) ? 0 : -1;
    }
    int low=0, high=n-1;
    while( low<=high ){

        if (A[low] <= A[high] && ( key < A[low] || key > A[high]) ) {
             return -1;
        }

        int mid = low + (high-low)/2;
        if ( A[mid] == key ) return mid;
    
        //the target in non-rotated array
        if (A[low] < A[mid] && key >= A[low] && key< A[mid]){
            high = mid - 1;
            continue;
        }
        //the target in non-rotated array
        if (A[mid] < A[high] && key > A[mid] && key <= A[high] ){
            low = mid + 1;
            continue;
        }
        //the target in rotated array
        if (A[low] > A[mid] ){
            high = mid - 1;
            continue;
        }
        //the target in rotated array
        if (A[mid] > A[high] ){
            low = mid + 1;
            continue;
        }
    }
    return -1;
}

int search2(int A[], int n, int target) {
    if (n<=0) return -1;

    if (n==1){
        return A[0]==target?0:-1;
    }        

    if ( A[0] < A[n-1] ){
        return binary_search(A, n, target);
    }else{
        return rotate_search(A, 0, n-1, target);
    }
}

int rotate_search(int A[], int low, int high, int key ) {
    
    if (low > high){
        return -1;
    }
    if (low==high){
        return A[low]==key?low:-1;
    }        
    
    int mid = low + (high-low)/2;
    if ( A[mid] == key ) return mid;

    if (A[low] < A[mid] && key >= A[low] && key< A[mid]){
        return binary_search(A, low, mid-1, key);
    }
    if (A[mid] < A[high] && key > A[mid] && key <= A[high] ){
        return binary_search(A, mid+1, high, key);
    }
    if (A[low] > A[mid] ){
        return rotate_search(A, low, mid-1, key);
    }
    if (A[mid] > A[high] ){
        return rotate_search(A, mid+1, high, key);
    }
    return -1;
}

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
    return -1;
}

int binary_search(int A[], int low, int high, int key) {
    //(low+high)/2 could encounter overflow issue
    int mid = low+(high-low)/2;
    if (low > high){
        return -1;
    }
    if (A[mid]==key){
        return mid;
    }
    if (key > A[mid]){
        binary_search(A, mid+1, high, key);
    }else{
        binary_search(A, low, mid-1, key);
    }

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

   for(int n=0; n<=cnt; n++) {
        printf("--------------------------------------\n");
        int *a = new int[cnt];
        for(int i=0; i<cnt; i++){
            a[i]=i*2;
        }
        //printArray(a, cnt);
        int rotate = random() % cnt;
        //rotate=2;
        //printf("rotate=%d\n", rotate);
        rotate_array(a, cnt, rotate);
        printArray(a, cnt);
        int target = random() % (2*cnt);
        //target=6;
        printf("target=%d\n", target);
    
        int idx = search(a, cnt, target);
        if ( idx<0 ){
            printf("not found!\n");
        }else{
            printf("a[%d] = %d\n", idx, a[idx]); 
        }
        
        delete[] a;
   }

    return 0;
}
