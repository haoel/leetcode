// Source : https://leetcode.com/problems/single-number/description/
// Author : Anas Mak
// Date   : 2023-01-25

/**********************************************************************************
 Given a non-empty array of integers nums, every element appears twice except for one.
 Find that single one.

 You must implement a solution with a linear runtime complexity and
 use only constant extra space.

 Here are few examples.
 Example 1:

 Input: nums = [2,2,1]
 Output: 1
 Example 2:

 Input: nums = [4,1,2,1,2]
 Output: 4
 Example 3:

 Input: nums = [1]
 Output: 1

 * 
 **********************************************************************************/
package Solution;

 class Solution {
    public int singleNumber(int[] nums) {
        
        Set <Integer> single = new HashSet <> ();
        for(int i : nums){
            if(!single.contains(i)){
                single.add(i);
            }

            else{
                single.remove(i);
            }
        }

        for(int result : single){
            return result;
        }
    
        return -1;
    }   
}