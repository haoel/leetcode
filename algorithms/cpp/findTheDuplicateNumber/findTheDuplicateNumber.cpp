// Source : https://leetcode.com/problems/find-the-duplicate-number/
// Author : Hao Chen, Calinescu Valentin
// Date   : 2015-10-19

/*************************************************************************************** 
 *
 * Given an array nums containing n + 1 integers where each integer is between 1 and 
 * n (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 *
 * Note:
 * > You must not modify the array (assume the array is read only).
 * > You must use only constant, O(1) extra space.
 * > Your runtime complexity should be less than O(n2).
 * > There is only one duplicate number in the array, but it could be repeated more than
 *   once.
 *
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test
 * cases.
 *               
 ***************************************************************************************/


class Solution {
public:
    //
    // This problem can be transfromed to "Linked List Cycle" problem.
    // There are two pointers, one goes one step, another goes two steps.
    //
    // Refer to: https://en.wikipedia.org/wiki/Cycle_detection
    //
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int one = n;
        int two = n;

       do{
            one = nums[one-1];
            two = nums[nums[two-1]-1];
        } while(one != two); 
        
        //find the start point of the cycle
        one = n;
        while(one != two){
            one = nums[one-1];
            two = nums[two-1];
        }
        
        return one;
    }
};
