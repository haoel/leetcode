// Source : https://oj.leetcode.com/problems/remove-element/
// Author : Hao Chen
// Date   : 2014-06-19

/********************************************************************************** 
* 
* Given an array and a value, remove all instances of that value in place and return the new length.
* 
* The order of elements can be changed. It doesn't matter what you leave beyond the new length.
* 
*               
**********************************************************************************/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] != val){
                nums[pos++] = nums[i]; 
            }
        }
        return pos;
    }

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
