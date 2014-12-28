// Source : https://oj.leetcode.com/problems/longest-palindromic-substring/
// Author : Hao Chen
// Date   : 2014-07-17

/********************************************************************************** 
* 
* Given a string S, find the longest palindromic substring in S. 
* You may assume that the maximum length of S is 1000, 
* and there exists one unique longest palindromic substring.
*               
**********************************************************************************/

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
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


// This is the common solution.
// Actuatlly it's faster than DP solution under Leetcode's test
// the below optimized DP solution need 700ms+, this needs around 250ms.
string longestPalindrome_recursive_way(string s) {
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


// Time/Memory Limit Exceeded
string longestPalindrome_dp_way(string s) {

    string longest;

    int n = s.size();
    if (n<=1) return s;
    
    //Construct a matrix, and consdier matrix[i][j] as s[i] -> s[j] is Palindrome or not.

    //using char or int could cause the `Memory Limit Error`
    //vector< vector<char> > matrix (n, vector<char>(n));

    //using bool type could cause the `Time Limit Error`
    vector< vector<bool> > matrix (n, vector<bool>(n));

    // Dynamic Programming 
    //   1) if i == j, then matrix[i][j] = true;
    //   2) if i != j, then matrix[i][j] = (s[i]==s[j] && matrix[i+1][j-1])
    for (int i=n-1; i>=0; i--){
        for (int j=i; j<n; j++){
            // The following if statement can be broken to 
            //   1) i==j, matrix[i][j] = true
            //   2) the length from i to j is 2 or 3, then, check s[i] == s[j]
            //   3) the length from i to j > 3, then, check s[i]==s[j] && matrix[i+1][j-1]
            if ( i==j || (s[i]==s[j] && (j-i<2 || matrix[i+1][j-1]) ) )  {
                matrix[i][j] = true;
                if (longest.size() < j-i+1){
                    longest = s.substr(i, j-i+1);
                }
            }
        }
    }

    return longest;
}

// Optimized DP soltuion can be accepted by LeetCode.
string longestPalindrome_dp_opt_way(string s) {

    int n = s.size();
    if (n<=1) return s;

    //Construct a matrix, and consdier matrix[j][i] as s[i] -> s[j] is Palindrome or not.
    //                                 ------^^^^^^
    //                                 NOTE: it's [j][i] not [i][j]

    //Using vector  could cause the `Time Limit Error`
    //So, use the native array
    bool **matrix  = new bool* [n];
    int start=0, len=0;
    // Dynamic Programming
    //   1) if i == j, then matrix[i][j] = true;
    //   2) if i != j, then matrix[i][j] = (s[i]==s[j] && matrix[i-1][j+1])
    for (int i=0; i<n; i++){
        matrix[i] = new bool[i+1];
        memset(matrix[i], false, (i+1)*sizeof(bool));
        matrix[i][i]=true;
        for (int j=0; j<i; j++){
            // The following if statement can be broken to
            //   1) j==i, matrix[i][j] = true
            //   2) the length from j to i is 2 or 3, then, check s[i] == s[j]
            //   3) the length from j to i > 3, then, check s[i]==s[j] && matrix[i-1][j+1]
            if ( i==j || (s[j]==s[i] && (i-j<2 || matrix[i-1][j+1]) ) )  {
                matrix[i][j] = true;
                if (len < i-j+1){
                    start = j;
                    len = i-j+1;
                }
            }
        }
    }

    for (int i=0; i<n; i++) { 
        delete [] matrix[i];
    }
    delete [] matrix;

    return s.substr(start, len);
}


string longestPalindrome(string s) {
    return longestPalindrome_dp_opt_way(s);
    return longestPalindrome_recursive_way(s);
}

int main(int argc, char**argv)
{
    string s = "abacdfgdcaba";
    if (argc > 1){
        s = argv[1];
    }
    cout <<  s << " : " << longestPalindrome(s) << endl;

    s = "321012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210123210012321001232100123210123";
    cout <<  s << " : " << longestPalindrome(s) << endl;
    return 0;
}
