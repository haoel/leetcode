// Source : https://oj.leetcode.com/problems/longest-palindromic-substring/
// Author : Hao Chen
// Date   : 2014-07-17

/********************************************************************************** 
* 
* Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*               
**********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

string findPalindrome(string s, int left, int right)
{
    int n = s.size();
    int l = left;
    int r = right;
    while (left>=0 && right<=n-1 && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left+1, right-left-1);
}


string longestPalindrome(string s) {
    int n = s.size();
    if (n<=1) return s;

    string longest;
    
    string str;
    for (int i=0; i<n-1; i++) {
        str = findPalindrome(s, i, i);
        if (str.size() > longest.size()){
            longest = str;
        } 
        str = findPalindrome(s, i, i+1);
        if (str.size() > longest.size()){
            longest = str;
        } 
    }

    return longest; 
}


int main(int argc, char**argv)
{
    string s = "abacdfgdcaba";
    if (argc > 1){
        s = argv[1];
    }
    cout <<  s << " : " << longestPalindrome(s) << endl;
    return 0;
}
