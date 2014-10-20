// Source : https://oj.leetcode.com/problems/remove-element/
// Author : Hao Chen
// Date   : 2014-06-19

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int tail = n-1;
        int i = 0;
        while ( i<=tail ){
            if (A[i]==elem){
                A[i] = A[tail--];
                continue;
            }
            i++;
        }
        
        return tail+1;
    }
};
