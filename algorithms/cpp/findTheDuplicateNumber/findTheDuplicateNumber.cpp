// Source : https://leetcode.com/problems/find-the-duplicate-number/
// Author : Calinescu Valentin
// Date   : 2015-10-19

/*************************************************************************************** 
 *
 * Given an array nums containing n + 1 integers where each integer is between 1 and 
 * n (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 *
 * Note:
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated more than
 * once.
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test
 * cases.
 *               
 ***************************************************************************************/



/* 
 * Solutions
 * =========
 *
 * A simple solution would be to sort the array and then look for equal consecutive elements.
 * 
 * Time Complexity: O(N log N)
 * Space Complexity: O(1)
 * 
 */
#include <algorithm>
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
            if(*it == *(it + 1))
                return *it;
    }
};
