// Source : https://leetcode.com/problems/longest-turbulent-subarray/
// Author : Hao Chen
// Date   : 2019-01-26

/***************************************************************************************************** 
 *
 * A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if and only if:
 * 
 * 	For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is even;
 * 	OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k is odd.
 * 
 * That is, the subarray is turbulent if the comparison sign flips between each adjacent pair of 
 * elements in the subarray.
 * 
 * Return the length of a maximum size turbulent subarray of A.
 * 
 * Example 1:
 * 
 * Input: [9,4,2,10,7,8,8,1,9]
 * Output: 5
 * Explanation: (A[1] > A[2] < A[3] > A[4] < A[5])
 * 
 * Example 2:
 * 
 * Input: [4,8,12,16]
 * Output: 2
 * 
 * Example 3:
 * 
 * Input: [100]
 * Output: 1
 * 
 * Note:
 * 
 * 	1 <= A.length <= 40000
 * 	0 <= A[i] <= 109
 * 
 ******************************************************************************************************/
class Solution {
public:
    
    int maxTurbulenceSize_01(vector<int>& A) {
        
        if (A.size() <= 1) return A.size();
        
        // declare status to mark the current pair status is go up or go down.
        enum Status {
            up,
            down,
            none
        } s = none;
        
        int maxlen = 1;
        int len = 1;
        
        for (int i=1; i< A.size(); i++) {
            
            // if there is a pair is equal, reset the status
            if ( A[i] == A[i-1] ) { 
                s = none;
                continue;
            }
            
            // init the first status
            if ( s == none ) {
                s = A[i] > A[i-1] ? up : down;
                len = 2;
                continue;
            }
            
            // keep tracking the status
            // make sure the status is zigzag pattern...up-down-up-down...
            if ( s == up ) {
                if ( A[i] < A[i-1] ) {
                    len++;
                    s = down;
                }else{
                    len=2;
                }
            }else{
                if ( A[i] > A[i-1] ) {
                    len++;
                    s = up;
                }else{
                    len=2;
                }
            }
            
            maxlen = len > maxlen ? len : maxlen;
            
        }
        return maxlen;
    }
    
    // The previous solution is quite straight forward, but the code is a bit complcated 
    // the following solution tries to use another way to make the code simpler.
    //
    // Then, we need to tracking the previous length of the zigzag pattern.
    //
    // And we have to tacking the length for both UP and DOWN patterns 
    //
    //   - UP means the previous status goes up. and the previous length of the zigzog pattern.
    //   - DOWN is same.
    //  
    // So,  
    //
    //   - if the previous is UP, then the previous DWON must be 1, and vice versa.
    //
    //   - the current UP could be two values : 1 or DOWN + 1 , and vice versa. 
    //      - if A[k] > A[k-1], UP = DWON +1, otherwise UP = 1
    //      - if A[K] < A[K-1], DOWN = UP + 1， otherise DOWN = 1
    //
    int maxTurbulenceSize_02(vector<int>& A) {
        
        if (A.size() <= 1) return A.size();
        
        int up = 1;
        int down = 1;
        int maxlen = 1;
        
        for (int k=1; k<A.size(); k++) {     
            //memory the previous UP and Down
            int u = up, d = down;
            
            up = (A[k] > A[k-1]) ? d + 1 : 1;
            down =  (A[k] < A[k-1]) ? u + 1 : 1;

            int len = down > up ? down : up;
            maxlen = len > maxlen ? len : maxlen;
        }
        return maxlen;
    }
    
    int maxTurbulenceSize(vector<int>& A) {
        return maxTurbulenceSize_02(A);
        return maxTurbulenceSize_01(A);
    }
};
