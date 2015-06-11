// Source : https://leetcode.com/problems/shortest-palindrome/
// Author : Hao Chen
// Date   : 2015-06-11

/********************************************************************************** 
 * 
 * Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. 
 * Find and return the shortest palindrome you can find by performing this transformation.
 * 
 * For example: 
 * Given "aacecaaa", return "aaacecaaa".
 * Given "abcd", return "dcbabcd".
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all test cases. 
 * Thanks to @Freezen for additional test cases.
 *               
 **********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool isPalindrome(string& s, int begin, int end) {
    for (; begin<end; begin++, end-- ) {
        if ( s[begin] != s[end] ) {
            return false;
        }
    }
    return true;
}

// Burst Force - - Time Limit Error
string shortestPalindrome_bf(string& s) {
    int len = s.size();
    int i;
    for (i=len-1; i>=0; i--) {
        if (isPalindrome(s, 0, i)) { 
            i++;
            break;
        }
    }
    string t = s.substr(i, len-i);
    reverse(t.begin(), t.end());
    return t+s;
}

//Dynamic Programming - Memory Limit Exceeded & Time Limit Error
//  Using the method of finding longest palindrome
string shortestPalindrome_dp(string& s) {
    int len = s.size();
    if (len <=1 ) return s;

    //find longest palindrome, see "Longest Palindromic Substring"
    vector< vector<bool> > dp(len, vector<bool>(len, false));
    for (int i=len-1; i>=0; i--){
        for(int j=i; j<len; j++){
            if (i==j || ((j-i==1 || dp[i+1][j-1]) && s[i]==s[j]) ) {
                dp[i][j] = true;
            }
        } 
    }  

    /*
     *   // only use two lines  -- still have Time Limit Error
     *
     *   vector< vector<bool> > dp(2, vector<bool>(len, false));
     *   for (int i=len-1; i>=0; i--){
     *       for(int j=i; j<len; j++){
     *           if (i==j || ((j-i==1 || dp[(i+1)%2][j-1]) && s[i]==s[j]) ) {
     *               dp[i%2][j] = true;
     *           }
     *       }
     *   }
     */
    
    //find the longest palindrome which start from first char.
    int pos = 0;
    for (int i=1; i<len; i++)  {
        if (dp[0][i]) {
            pos = i+1;
        } 
    }
    string t = s.substr(pos, len - pos);
    reverse(t.begin(), t.end());
    return t+s;
    
}

/*
 *   The core of KMP algorithm needs to build a partial match table for pattern, 
 *   which can determin how many chars need to skip if mismatch happens.
 *
 *   The best explaination of the idea of the KMP algorithm is:
 *   http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/
 *
 *   Here, we can use KMP algorithm to solve this problem.
 *
 *   1) We need construct a mirror string base on original string. and use a uniq char for seperator.
 *
 *       considering the original string is "abab", then the mirror string is "abab#baba" (# is seperator)
 *
 *   2) Build the KMP partial match table for this pattern.
 *
 *       a b a b # b a b a
 *       0 0 1 2 0 0 1 2 3
 *
 *   3) Checking the last position of partial match table, it is 3. it means:
 *
 *      For the entire pattern (mirror string), there has max 3 length of sub-string is both prefix and suffix.
 *      
 *      This sub-string is "aba".
 *
 *   4) The result of 3) is really useful to solve this shorest  palindrome problem.
 *
 *      Because "aba" is the pattern which in original string and its reversed version.
 *
 *      ( Note: The uniq char is used for making the noise, which can make sure 
 *              the original string and its reversed version won't be mixed.
 *              then, the common prefix and suffix sub-string is right )
 *
 *      So, if a sub-string "aba" is existed in both original string and its reversed version,
 *      which means, this is the longest prefix palindrome.
 *
 *    5) Then, we can take rest suffix, and reverse it and put it in front of original string.
 *
 */

string shortestPalindrome_kmp(string& s) {  
    int len = s.size();
    if(len <= 1) return s;
    
    string pattern = s + '\0' + string(s.rbegin(), s.rend());  

    //construct the partial match table
    vector<int> prefix( pattern.size() );  
    prefix[0] = 0;
    for(int i = 1; i < prefix.size(); i++) {  
        int j = prefix[i-1];  
        while( j > 0 && pattern[i] != pattern[j] ) {
            j = prefix[j-1];  
        }
        if ( pattern[i] == pattern[j] ) {
            j++;  
        }
        prefix[i] = j;  
    }  

#ifdef _DEBUG
    cout << endl;
    for(int i=0; i<pattern.size(); i++){
        
        cout << (pattern[i] ? pattern[i] : '#') << "  ";
    }
    cout << endl;
    for(int i=0; i<prefix.size(); i++) {
        cout << prefix[i] << "  ";
    }
    cout << endl;
    cout << "-->" << s.substr(0, prefix.back()) << " " << s.substr(prefix.back()) << endl;
#endif

    int pos = s.size() - prefix.back();  
    return string(s.rbegin(), s.rbegin() + pos) + s;  
}  


string shortestPalindrome(string s) {
    return shortestPalindrome_kmp(s); 
    return shortestPalindrome_dp(s); //Memory Limit Error
    return shortestPalindrome_bf(s); //Time Limit Error
}
#define TEST(s)  cout << s << " : " << shortestPalindrome(s) << endl

int main(int argc, char**argv)
{
    string s = "aabba";
    if (argc>1){
        s = argv[1];
    }
    TEST(s);
    TEST("a");
    TEST("ab");
    TEST("aba");
    TEST("abab");
    TEST("aabb");
    TEST("aacecaaa");
    TEST("abcd");
    TEST("aaabcb");
    return 0;
}
