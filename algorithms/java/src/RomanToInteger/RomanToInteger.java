// Source : https://leetcode.com/problems/roman-to-integer/
// Author : Diego Ruiz Piqueras (Pikeras72)
// Date   : 23-04-2022

/***************************************************************************************************** 
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, 2 is written as II in Roman numeral, just two one's added
 * together. 12 is written as XII, which is simply X + II. The number 27 is
 * written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making four.
 * The same principle applies to the number nine, which is written as IX. There
 * are six instances where subtraction is used:
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * Given an integer, convert it to a roman numeral.
 * 
 * Example 1:
 * 
 * Input: s = "III"
 * Output: 3
 * Explanation: III = 3.
 * 
 * Example 2:
 *
 * Input: s = "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * 
 * Example 3:
 *
 * Input: s = "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 * Constraints:
 * 
 *  1 <= s.length <= 15
 *  s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
 *  It is guaranteed that s is a valid roman numeral in the range [1, 3999].
 * 
 * Explanation of the solution:
 * 
 * Letters 'V' ,'L', 'D' and 'M' can't be subtracted so when they are readed we can just add their values.
 * 
 * In contrast, the letter 'I' can be subtracted at 4 and 9... Example: IV = 4, IX = 9. 
 * If the letter 'I' is at the end of the number, we just add it's value.
 * 
 * Letter 'X' can be subtracted at 40 and 90... Example: XL = 40, XC = 90.
 * 
 * Letter 'C' can be subtracted at 400 and 900... Example: CD = 400, CM = 900.
 * 
 * I used an array to store the values, but you could perfectly just write the values of it's letters.
 * 
 * While reading the next letter you should check that it's not the last one, I used "if( i != s.length()-1 && ... )"
 ******************************************************************************************************/

class Solution {
    public int romanToInt(String s) {
       int[] nums = {1,5,10,50,100,500,1000};
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == 'I'){
                if(i != s.length()-1 && s.charAt(i+1) == 'V'){
                    res += nums[1]-nums[0];
                    i++;
                }else if(i != s.length()-1 && s.charAt(i+1) == 'X'){
                    res += nums[2]-nums[0];
                    i++;
                }else{
                    res += nums[0];
                }
            }else if(s.charAt(i) == 'V'){
                res += nums[1];
            }else if(s.charAt(i) == 'X'){
                if(i != s.length()-1 &&  s.charAt(i+1) == 'C'){
                    res += nums[4]-nums[2];
                    i++;
                }else if(i != s.length()-1 &&  s.charAt(i+1) == 'L'){
                    res += nums[3]-nums[2];
                    i++;
                }else{
                    res += nums[2];
                }
            }else if(s.charAt(i) == 'L' ){
                res += nums[3];
            }else if(s.charAt(i) == 'C'){
                if(i != s.length()-1 && s.charAt(i+1) == 'D'){
                    res += nums[5]-nums[4];
                    i++;
                }else if(i != s.length()-1 && s.charAt(i+1) == 'M'){
                    res += nums[6]-nums[4];
                    i++;
                }else{
                    res += nums[4];
                }
            }else if(s.charAt(i) == 'D'){
                res += nums[5];
            }else if(s.charAt(i) == 'M'){
                res += nums[6];
            }
        }
        return res;
    }
}
