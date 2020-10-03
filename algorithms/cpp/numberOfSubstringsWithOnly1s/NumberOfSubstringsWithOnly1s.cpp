// Source : https://leetcode.com/problems/number-of-substrings-with-only-1s/
// Author : Hao Chen
// Date   : 2020-10-03

/***************************************************************************************************** 
 *
 * Given a binary string s (a string consisting only of '0' and '1's).
 * 
 * Return the number of substrings with all characters 1's.
 * 
 * Since the answer may be too large, return it modulo 10^9 + 7.
 * 
 * Example 1:
 * 
 * Input: s = "0110111"
 * Output: 9
 * Explanation: There are 9 substring in total with only 1's characters.
 * "1" -> 5 times.
 * "11" -> 3 times.
 * "111" -> 1 time.
 * 
 * Example 2:
 * 
 * Input: s = "101"
 * Output: 2
 * Explanation: Substring "1" is shown 2 times in s.
 * 
 * Example 3:
 * 
 * Input: s = "111111"
 * Output: 21
 * Explanation: Each substring contains only 1's characters.
 * 
 * Example 4:
 * 
 * Input: s = "000"
 * Output: 0
 * 
 * Constraints:
 * 
 * 	s[i] == '0' or s[i] == '1'
 * 	1 <= s.length <= 10^5
 ******************************************************************************************************/

class Solution {
public:
    // 11 - 1+2
    // 111 - 1+2+3
    // 1111 - 1+2+3+4
    // 11111 - 1+2+3+4+5
    // so, we just simply find the length of continuous '1',
    // then, the answer it len*(len+1)/2
    int numSub(string s) {
       long long len=0;
       long long result=0;
        for (auto c : s) {
            if (c=='1') {
                len++;
                continue;
            }
            if (len > 0){
                result += len*(len+1)/2;
                len = 0;
            }
        }

        result += len*(len+1)/2;
        return result % 1000000007 ;
    }
};
