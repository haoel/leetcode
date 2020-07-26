// Source : https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/
// Author : Hao Chen
// Date   : 2020-07-26

/***************************************************************************************************** 
 *
 * Given an array of integers A, find the number of triples of indices (i, j, k) such that:
 * 
 * 	0 <= i < A.length
 * 	0 <= j < A.length
 * 	0 <= k < A.length
 * 	A[i] & A[j] & A[k] == 0, where & represents the bitwise-AND operator.
 * 
 * Example 1:
 * 
 * Input: [2,1,3]
 * Output: 12
 * Explanation: We could choose the following i, j, k triples:
 * (i=0, j=0, k=1) : 2 & 2 & 1
 * (i=0, j=1, k=0) : 2 & 1 & 2
 * (i=0, j=1, k=1) : 2 & 1 & 1
 * (i=0, j=1, k=2) : 2 & 1 & 3
 * (i=0, j=2, k=1) : 2 & 3 & 1
 * (i=1, j=0, k=0) : 1 & 2 & 2
 * (i=1, j=0, k=1) : 1 & 2 & 1
 * (i=1, j=0, k=2) : 1 & 2 & 3
 * (i=1, j=1, k=0) : 1 & 1 & 2
 * (i=1, j=2, k=0) : 1 & 3 & 2
 * (i=2, j=0, k=1) : 3 & 2 & 1
 * (i=2, j=1, k=0) : 3 & 1 & 2
 * 
 * Note:
 * 
 * 	1 <= A.length <= 1000
 * 	0 <= A[i] < 2^16
 * 
 ******************************************************************************************************/

class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size();

        //using a map to aggregate the duplication
        unordered_map<int, int> rec;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                rec[A[i] & A[j]]++;
            }
        }

        int result = 0;
        for (auto &r : rec ) {
            for (int k=0; k<n; k++) {
                if ((r.first & A[k]) == 0) result+=r.second;
            }
        }
        return result;
    }

};
