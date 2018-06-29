// Source : https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
// Author : Hao Chen
// Date   : 2018-06-29

/*************************************************************************************** 
 *
 * Let's call an array A a mountain if the following properties hold:
 * 
 * 
 * 	A.length >= 3
 * 	There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < 
 * A[i] > A[i+1] > ... > A[A.length - 1]
 * 
 * 
 * Given an array that is definitely a mountain, return any i such that A[0] < A[1] < 
 * ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
 * 
 * Example 1:
 * 
 * 
 * Input: [0,1,0]
 * Output: 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,2,1,0]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * 
 * 	3 <= A.length <= 10000
 * 	0 <= A[i] <= 10^6
 * 	A is a mountain, as defined above.
 * 
 ***************************************************************************************/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        
        // Put two dummy items at head and tail to avoid Out-of-Bound Error.
        #define INT_MAX 2147483647
        #define INT_MIN (-INT_MAX - 1)
        A.insert ( A.begin() , INT_MIN );
        A.push_back(INT_MIN);
        
        //binary search
        int len = A.size();
        int left = 1, right = len - 2;
        while(left <= right) {
            int mid = left + (right - left)/2; //avoid integer overflow
            if ( A[mid-1] < A[mid] && A[mid] > A[mid+1]) return mid-1;
            if ( A[mid-1] < A[mid] && A[mid] < A[mid+1]) left = mid + 1;
            if ( A[mid-1] > A[mid] && A[mid] > A[mid+1]) right = mid - 1;
            
        }
        return -1;
    }
};

