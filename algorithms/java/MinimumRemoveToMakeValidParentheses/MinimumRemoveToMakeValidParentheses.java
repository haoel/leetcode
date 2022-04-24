// Source : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// Author : Diego Ruiz Piqueras (Pikeras72)
// Date   : 24-04-2022

/***************************************************************************************************** 
 *
 * Given a string s of '(' , ')' and lowercase English characters.
 * 
 * Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) 
 * so that the resulting parentheses string is valid and return any valid string.
 * 
 * Formally, a parentheses string is valid if and only if:
 * It is the empty string, contains only lowercase characters, or
 * It can be written as AB (A concatenated with B), where A and B are valid strings, or
 * It can be written as (A), where A is a valid string.
 * 
 * Example 1:
 * 
 * Input: s = "lee(t(c)o)de)"
 * Output: "lee(t(c)o)de"
 * Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
 * 
 * Example 2:
 *
 * Input: s = "a)b(c)d"
 * Output: "ab(c)d"
 * 
 * Example 3:
 *
 * Input: s = "))(("
 * Output: ""
 * Explanation: An empty string is also valid.
 * 
 * Constraints:
 * 
 *  1 <= s.length <= 10^5
 *  s[i] is either'(' , ')', or lowercase English letter.
 * 
 * Explanation of the solution:
 * 
 * 1. Analyze the string to know how many valid parentheses are in 's'.
 * 
* 2. Analyze again the string and return the string deleting the invalid parentheses.
* 
* 3. Return the reversed string.
 ******************************************************************************************************/

class Solution {
   public String minRemoveToMakeValid(String s) {
        StringBuilder comprobar = new StringBuilder();
        int open = 0;
        for(char c : s.toCharArray()) {
            if(c =='(') {
                open++;
            }
            else if(c == ')') {
                if(open == 0) continue;
                open--;
            }
            comprobar.append(c);
        }
        StringBuilder result = new StringBuilder();
        for(int i=comprobar.length()-1 ; i>=0 ; i-- ){
            if(comprobar.charAt(i) == '(' && open-- > 0) continue;
            result.append(comprobar.charAt(i));
        }
        return result.reverse().toString();
    }
}
