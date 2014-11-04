// Source : https://oj.leetcode.com/problems/search-for-a-range/
// Author : Hao Chen
// Date   : 2014-06-26

/********************************************************************************** 
* 
* Given a sorted array of integers, find the starting and ending position of a given target value.
* 
* Your algorithm's runtime complexity must be in the order of O(log n).
* 
* If the target is not found in the array, return [-1, -1].
* 
* For example,
* Given [5, 7, 7, 8, 8, 10] and target value 8,
* return [3, 4].
* 
*               
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int binary_search(int A[], int low, int high, int key);

/*
 *   O(log n) solution must be something like binary search.
 *
 *   So, we can use the binary search to find the one postion - `pos`
 *   
 *   then, we can keep using the binary search find the target in A[0..pos-1] and A[pos+1..n]
 *
 *   The code below is self-explaination
 */
vector<int> searchRange(int A[], int n, int target) {
    int pos = binary_search(A, 0, n-1, target);

    vector<int> v;
    int low = -1, high = -1;
    if (pos >=0){
        low = high = pos;
        int l = low;
        do {
            low = l;
            l = binary_search(A, 0, low - 1, target);
        }while (l>=0);

        int h = high;
        do {
            high = h;
            h = binary_search(A, high + 1, n-1, target);
        }while (h>=0);
    }

    v.push_back(low);
    v.push_back(high);
    return v;

}

int binary_search(int A[], int low, int high, int key){

    while (low<=high) {
        int mid = low + (high-low)/2;
        if (A[mid] == key) {
            return mid;
        }
        if (key > A[mid]) {
            low = mid + 1;
        }
        if (key < A[mid]) {
            high = mid - 1;
        }
    }
    return -1;
}

void printVector( vector<int>&  pt)
{
    cout << "{ ";
    for(int j=0; j<pt.size(); j++){
        cout << pt[j] << " ";
    }
    cout << "} " << endl;
}


int main()
{
    const int cnt=6;
    int a[cnt] ={5, 7, 7, 8, 8, 10};

    vector<int> v;
    v = searchRange(a, cnt, 8);     
    printVector(v);    


    int b[cnt] ={5, 5, 5, 8, 8, 10};
    v = searchRange(b, cnt, 5);     
    printVector(v);    

    int c[cnt] ={5, 5, 5, 5, 5, 5};
    v = searchRange(c, cnt, 5);     
    printVector(v);    
    return 0;
}
