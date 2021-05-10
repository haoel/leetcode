// Source : https://leetcode.com/problems/maximum-score-from-removing-substrings/
// Author : Hao Chen
// Date   : 2021-03-28

/***************************************************************************************************** 
 *
 * You are given a string s and two integers x and y. You can perform two types of operations any 
 * number of times.
 * 
 * 	Remove substring "ab" and gain x points.
 * 
 * 		For example, when removing "ab" from "cabxbae" it becomes "cxbae".
 * 
 * 	Remove substring "ba" and gain y points.
 * 
 * 		For example, when removing "ba" from "cabxbae" it becomes "cabxe".
 * 
 * Return the maximum points you can gain after applying the above operations on s.
 * 
 * Example 1:
 * 
 * Input: s = "cdbcbbaaabab", x = 4, y = 5
 * Output: 19
 * Explanation:
 * - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the 
 * score.
 * - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the 
 * score.
 * - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
 * - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
 * Total score = 5 + 4 + 5 + 5 = 19.
 * 
 * Example 2:
 * 
 * Input: s = "aabbaaxybbaabb", x = 5, y = 4
 * Output: 20
 * 
 * Constraints:
 * 
 * 	1 <= s.length <= 10^5
 * 	1 <= x, y <= 10^4
 * 	s consists of lowercase English letters.
 ******************************************************************************************************/

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char key[] ="ab";
        if (y > x) { key[0] = 'b'; key[1]='a';}
        
        int high = max(x,y);
        int low = min(x,y);
        
        //greedy for high score
        int score = 0;
        stack<char> left_stack;
        for (int i=0; i<s.size(); i++) {
            char c = s[i];
            if (  left_stack.empty()  ||  //stack is empty, just push directly
                 ( c != key[0] && c != key[1] ) ) { // not the score char, just tpush cirectory
                left_stack.push(c);
                continue;
            }

            // if we meet the high score pattern
            if ( c == key[1] && left_stack.top() == key[0]){
                //cout << key << endl;
                left_stack.pop();
                score += high;
                continue;
            }
            left_stack.push(c);
        }
        
        //process the low score
        stack<char> right_stack;
        while(!left_stack.empty()) {
            char c = left_stack.top();  left_stack.pop();
            if (right_stack.empty() || c != key[0] && c != key[1]) {
                right_stack.push(c);
                continue;
            }
            // if we meet the low score pattern
            if ( c == key[1] && right_stack.top() == key[0]){
                right_stack.pop();
                score += low;
                continue;
            }
            
            right_stack.push(c);
        }
        return score;
    }
};
