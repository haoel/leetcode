// Source : https://leetcode.com/problems/integer-to-roman/
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
 * Input: num = 3
 * Output: "III"
 * Explanation: 3 is represented as 3 ones.
 * 
 * Example 2:
 *
 * Input: num = 58
 * Output: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.
 * 
 * Example 3:
 *
 * Input: num = 1994
 * Output: "MCMXCIV"
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 * Constraints:
 * 
 *  1 <= num <= 3999
 * 
 * Explanation of the solution:
 * 
 * We start looking if the number given is bigger than 1000
 * to see if there is going to be a letter 'M' (1000) in the solution.
 * 
 * If the number > 1000 we repeat the process until a maximun of three 'M' 
 * substracting 1000 to the number each time.
 * 
 * The process is the same for all the letters.
 * 
 * We also analyze special cases such as 'CM' (num < 1000 && num > 899), 'CD' (num < 500 && num > 399),
 * 'XC' (num < 100 && num > 89), 'XL' (num < 50 && num > 39), 'IX' (num == 9) and 'IV' (num == 4).
 ******************************************************************************************************/

class Solution {
    public String intToRoman(int num) {
        String res = "";
        int cnt = 0;
        while(num >= 1000 && cnt < 3){
                res += "M";
                num -= 1000;
                cnt++;
        }
        cnt = 0;
        if(num < 1000 && num > 899){
            res += "CM";
            num -= 900;
        }
        while(num >= 500 && cnt < 3){
                res += "D";
                num -= 500;
                cnt++;
        }    
        cnt = 0;
        if(num < 500 && num > 399){
            res += "CD";
            num -= 400;
        }
        while(num >= 100 && cnt < 3){
                res += "C";
                num -= 100;
                cnt++;
        }    
        cnt = 0;
        if(num < 100 && num > 89){
            res += "XC";
            num -= 90;
        }
            while(num >= 50 && cnt < 3){
                res += "L";
                num -= 50;
                cnt++;
            }
            cnt = 0;
        if(num < 50 && num > 39){
            res += "XL";
            num -= 40;
        }
            while(num >= 10 && cnt < 3){
                res += "X";
                num -= 10;
                cnt++;
            }
            cnt = 0;
        if(num == 9){
            res += "IX";
            num -= 9;
        }
            while(num >= 5 && cnt < 3){
                res += "V";
                num -= 5;
                cnt++;
            }
            cnt = 0;
        if(num == 4){
            res += "IV";
            num -= 4;
        }
             while(num >= 1 && cnt < 3){
                res += "I";
                num -= 1;
                 cnt++;
            }
        return res;
    }
}
