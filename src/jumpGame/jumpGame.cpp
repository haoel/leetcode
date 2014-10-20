// Source : https://oj.leetcode.com/problems/jump-game/
// Author : Hao Chen
// Date   : 2014-06-27

class Solution {
public:
    bool canJump(int A[], int n) {
        if (n<=0) return false;
        
        int coverPos=0;
        for(int i=0; i<=coverPos && i<n; i++){
            
            if (coverPos < A[i] + i){
                coverPos = A[i] + i;
            }
            
            if (coverPos>=n-1){
                return true;
            }
        }
        return false;
    }
};
