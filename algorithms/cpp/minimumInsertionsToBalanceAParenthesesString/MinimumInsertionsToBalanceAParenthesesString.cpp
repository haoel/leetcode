// Source : https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
// Author : Hao Chen
// Date   : 2020-10-02

/***************************************************************************************************** 
 *
 * Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is 
 * balanced if:
 * 
 * 	Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
 * 	Left parenthesis '(' must go before the corresponding two consecutive right parenthesis 
 * '))'.
 * 
 * In other words, we treat '(' as openning parenthesis and '))' as closing parenthesis.
 * 
 * For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not 
 * balanced.
 * 
 * You can insert the characters '(' and ')' at any position of the string to balance it if needed.
 * 
 * Return the minimum number of insertions needed to make s balanced.
 * 
 * Example 1:
 * 
 * Input: s = "(()))"
 * Output: 1
 * Explanation: The second '(' has two matching '))', but the first '(' has only ')' matching. We need 
 * to to add one more ')' at the end of the string to be "(())))" which is balanced.
 * 
 * Example 2:
 * 
 * Input: s = "())"
 * Output: 0
 * Explanation: The string is already balanced.
 * 
 * Example 3:
 * 
 * Input: s = "))())("
 * Output: 3
 * Explanation: Add '(' to match the first '))', Add '))' to match the last '('.
 * 
 * Example 4:
 * 
 * Input: s = "(((((("
 * Output: 12
 * Explanation: Add 12 ')' to balance the string.
 * 
 * Example 5:
 * 
 * Input: s = ")))))))"
 * Output: 5
 * Explanation: Add 4 '(' at the beginning of the string and one ')' at the end. The string becomes 
 * "(((())))))))".
 * 
 * Constraints:
 * 
 * 	1 <= s.length <= 10^5
 * 	s consists of '(' and ')' only.
 ******************************************************************************************************/
class Solution {
public:
    int minInsertions(string s) {
        vector<char> stack;
        
        int cnt = 0;
        int len = s.size();
        for (int i=0; i<len; i++) {
            
            if ( s[i] == '(' ) {
                stack.push_back( s[i] );
                continue;
            }
            // if s[i] is ')'
            if (stack.size() > 0)  {
                stack.pop_back();
            } else {
                cnt++; // missed the '('
            }
            
            // if  s[i+1] is ')', need to skip
            if ( i < len -1 && s[i+1] == ')' ) {
                i++;
            }else{
                cnt++; //missed the ')'
            }
         
        }
        
        // if the stack still has '(', which means need double of ')'
        return cnt + stack.size()*2;
    }
};
