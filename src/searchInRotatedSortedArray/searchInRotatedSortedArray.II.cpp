// Source : https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author : Hao Chen
// Date   : 2014-06-29

class Solution {
public:
    bool search(int A[], int n, int key) {
        if (n<=0) return false;
    
        if (n==1){
            return (A[0]==key) ? true : false;
        }
        int low=0, high=n-1;
        while( low<=high ){
    
            if (A[low] < A[high] && ( key < A[low] || key > A[high]) ) {
                 return false;
            }
            
            //if dupilicates, them binary search the duplication
            
            while (low < high && A[low]==A[high]){
                low++;
            }
    
            int mid = low + (high-low)/2;
            if ( A[mid] == key ) return true;
    
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
            
            //reach here means nothing found.
            low++;
        }
        return false;
    }
    
    
};
