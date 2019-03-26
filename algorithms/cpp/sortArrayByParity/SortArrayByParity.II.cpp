// Source : https://leetcode.com/problems/sort-array-by-parity-ii/
// Author : Hao Chen
// Date   : 2019-03-26

/***************************************************************************************************** 
 *
 * Given an array A of non-negative integers, half of the integers in A are odd, and half of the 
 * integers are even.
 * 
 * Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.
 * 
 * You may return any answer array that satisfies this condition.
 * 
 * Example 1:
 * 
 * Input: [4,2,5,7]
 * Output: [4,5,2,7]
 * Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
 * 
 * Note:
 * 
 * 	2 <= A.length <= 20000
 * 	A.length % 2 == 0
 * 	0 <= A[i] <= 1000
 * 
 ******************************************************************************************************/

class Solution {
public:
    bool isEven(int &x) {
        return x % 2 == 0;
    }
    vector<int> sortArrayByParityII(vector<int>& A) {
        //two pointer, `even` and `odd`,
        //  - `even` pointer step into even position
        //  - `odd` pointer step into odd position.
        // if `even` points to odd number, and `odd` points to even number switch them.
        int even = 0;
        int odd = 1;
        while(even < A.size() && odd < A.size() ) {
            if ( !isEven(A[even]) && isEven(A[odd]) ) swap( A[even], A[odd] );
            if ( isEven(A[even]) ) even += 2;
            if ( !isEven(A[odd]) ) odd += 2;
        }
        return A;
    }
};
