// Source : https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
// Author : Hao Chen
// Date   : 2021-03-13

/***************************************************************************************************** 
 *
 * The beauty of a string is the difference in frequencies between the most frequent and least 
 * frequent characters.
 * 
 * 	For example, the beauty of "abaacc" is 3 - 1 = 2.
 * 
 * Given a string s, return the sum of beauty of all of its substrings.
 * 
 * Example 1:
 * 
 * Input: s = "aabcb"
 * Output: 5
 * Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with 
 * beauty equal to 1.
 * 
 * Example 2:
 * 
 * Input: s = "aabcbaa"
 * Output: 17
 * 
 * Constraints:
 * 
 * 	1 <= s.length <= 500
 * 	s consists of only lowercase English letters.
 ******************************************************************************************************/

class Solution {
private:
    int beauty(string& s, int start, int end) {
        int stat[26] = {0};
        for (int i=start; i<=end; i++){
            stat[s[i]-'a']++;
        }
        int max = INT_MIN, min = INT_MAX; 
        for (auto s: stat) {
            if (s == 0 ) continue;
            max = s > max ? s : max;
            min = s < min ? s : min;
        }
        return max - min;
    }
public:
    int beautySum(string s) {
        return beautySum02(s);
        return beautySum01(s);
    }
    
    int beautySum01(string& s) {
        int sum = 0; 
        for (int i=0; i<s.size()-1; i++) {
            for (int j=i+1; j<s.size(); j++) {
                sum += beauty(s, i, j);
            }
        }
        return sum;
    }
    
    //same as beautySum01(), but optimazed slightly
    int beautySum02(string& s) {
        int sum = 0; 
        for (int i=0; i<s.size()-1; i++) {
            int stat[26] = {0};
            for (int j=i; j<s.size(); j++) {
                stat[s[j]-'a']++;
                int max = INT_MIN, min = INT_MAX; 
                for (auto& n: stat) {
                    if (n <= 0 ) continue; 
                    max = n > max ? n : max;
                    min = n < min ? n : min;
                }
                //cout << s.substr(i, j-i+1)  << " --> "<< max << ":" << min << endl;
                sum += (max - min);
            }
        }
        return sum;
    }
};
