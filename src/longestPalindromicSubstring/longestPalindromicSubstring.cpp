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

//Memory Limit Exceeded
string longestPalindrome_dp_way(string s) {

    string longest;

    int n = s.size();
    if (n<=1) return s;
    
    //Construct a matrix, and consdier matrix[i][j] as s[i] -> s[j] is Palindrome or not.
    vector< vector<int> > matrix (n, vector<int>(n));

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
string longestPalindrome(string s) {
    return longestPalindrome_dp_way(s);
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
