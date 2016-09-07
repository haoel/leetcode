// Source : https://leetcode.com/problems/decode-string/
// Author : Hao Chen
// Date   : 2016-09-08

/*************************************************************************************** 
 *
 * Given an encoded string, return it's decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the square 
 * brackets is being repeated exactly k times. Note that k is guaranteed to be a 
 * positive integer.
 * 
 * You may assume that the input string is always valid; No extra white spaces, square 
 * brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any digits and 
 * that digits are only for those repeat numbers, k. For example, there won't be input 
 * like 3a or 2[4].
 * 
 * Examples:
 * 
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 ***************************************************************************************/

class Solution {
public:
    string decodeString(string s) {
        if (!isValid(s)) return "";
        
        stack<string> _stack;
        stack<int> _nstack;
        
        string result;
        string tmp;
        int n=0;
        for (int i=0; i<s.size(); i++) {
            
            if ( isNum(s[i]) ) {
                n = 0;
                for(; isNum(s[i]); i++ ) {
                   n = n*10 + s[i] - '0'; 
                }
            }
            
            if (s[i] == '[') {
                tmp="";
                _stack.push(tmp);
                _nstack.push(n);
            } else if (s[i] == ']') {
                n = _nstack.top(); 
                tmp="";
                for (; n>0; n--) {
                    tmp += _stack.top();
                }
                _stack.pop();
                _nstack.pop();
                if ( ! _stack.empty() ) {
                    _stack.top() += tmp;
                }else {
                    result += tmp;
                }
            } else {
                if ( ! _stack.empty() ) {
                    _stack.top() += s[i];
                } else {
                    result += s[i];
                }
                
            }
        }
        
        return result;
    }
    
private:

    //only check the following rules:
    // 1) the number must be followed by '['
    // 2) the '[' and ']' must be matched.
    bool isValid(string& s) {
        stack<char> _stack;
        for (int i=0; i<s.size(); i++) {
            if ( isNum(s[i]) ) {
                for(; isNum(s[i]); i++);
                if (s[i] != '[') {
                    return false;
                } 
                _stack.push('[');
                continue;
            } else if (s[i] == ']' ) {
                if ( _stack.top() != '[' ) return false;
                _stack.pop();
            }
        }
        
        return (_stack.size() == 0);
    }
    
    bool isNum(char ch) {
        return (ch>='0' && ch<='9');
    }
};

