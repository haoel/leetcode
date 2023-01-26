// Source : https://leetcode.com/problems/plus-one/description/
// Author : Anas Mak
// Date   : 2023-01-26

/**********************************************************************************
 * You are given a large integer represented as an integer array digits, 
 * where each digits[i] is the ith digit of the integer. 
 * The digits are ordered from most significant to least significant in left-to-right order.
 * The large integer does not contain any leading 0's.
 * Increment the large integer by one and return the resulting array of digits.
 **********************************************************************************/

package Solution;

 class Solution {
    public int[] plusOne(int[] digits) {
        for(int i = digits.length - 1 ; i >=0 ; i--){
            if(digits[i] != 9){
                digits[i]+=1;
                return digits;
            }

            else{
               digits[i] = 0;
            }
        }

        int[] array = new int[digits.length + 1];
        array[0] = 1;
        return array;
    }
}