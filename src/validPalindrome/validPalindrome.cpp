// Source : https://oj.leetcode.com/problems/valid-palindrome/
// Author : Hao Chen
// Date   : 2014-06-26

/********************************************************************************** 
* 
* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
* 
* For example,
* "A man, a plan, a canal: Panama" is a palindrome.
* "race a car" is not a palindrome.
* 
* Note:
* Have you consider that the string might be empty? This is a good question to ask during an interview.
* 
* For the purpose of this problem, we define empty string as valid palindrome.
* 
*               
**********************************************************************************/

class Solution {
public:
    bool isPalindrome(string s) {
        s = removeNoise(s);
        for(int i=0; i<s.size()/2; i++){
            if (s[i]!= s[s.size()-i-1]){
                return false;
            }
        }
        return true;
    }
    
    string removeNoise(string& s){
        string d;
        for(int i=0; i<s.size(); i++){
            if(::isalpha(s[i]) || ::isdigit(s[i])){
                d.push_back(::tolower(s[i]));
            }
        }
        return d;
    }
};
