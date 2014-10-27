// Source : https://oj.leetcode.com/problems/scramble-string/
// Author : Hao Chen
// Date   : 2014-10-09

/********************************************************************************** 
* 
* Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
* 
* Below is one possible representation of s1 = "great":
* 
*     great
*    /    \
*   gr    eat
*  / \    /  \
* g   r  e   at
*            / \
*           a   t
* 
* To scramble the string, we may choose any non-leaf node and swap its two children.
* 
* For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
* 
*     rgeat
*    /    \
*   rg    eat
*  / \    /  \
* r   g  e   at
*            / \
*           a   t
* 
* We say that "rgeat" is a scrambled string of "great".
* 
* Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
* 
*     rgtae
*    /    \
*   rg    tae
*  / \    /  \
* r   g  ta  e
*        / \
*       t   a
* 
* We say that "rgtae" is a scrambled string of "great".
* 
* Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
* 
*               
**********************************************************************************/

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// The recursive way is quite simple.
//    1) break the string to two parts: 
//          s1[0..j]   s1[j+1..n]
//          s2[0..j]   s2[j+1..n]
//    2) then
//          isScramble(s1[0..j], s2[0..j]) &&  isScramble(s1[j+1..n], s2[j+1..n])
//        OR
//          isScramble(s1[0..j], s2[j+1, n]) &&  isScramble(s1[j+1..n], s2[0..j])
bool isScramble_recursion(string s1, string s2) {

    if (s1.size()!= s2.size() || s1.size()==0 || s2.size()==0) {
        return false;
    }
    if (s1 == s2){
        return true;
    } 
    string ss1 = s1;
    string ss2 = s2;
    sort(ss1.begin(), ss1.end()); 
    sort(ss2.begin(), ss2.end()); 
    if (ss1 != ss2 ) {
        return false;
    }

    for (int i=1; i<s1.size(); i++) {
        if ( isScramble_recursion(s1.substr(0,i), s2.substr(0,i)) && 
             isScramble_recursion(s1.substr(i, s1.size()-i), s2.substr(i, s2.size()-i)) ) {
            return true;
        }
        if ( isScramble_recursion(s1.substr(0,i), s2.substr(s2.size()-i, i)) && 
             isScramble_recursion(s1.substr(i, s1.size()-i), s2.substr(0, s2.size()-i)) ) {
            return true;
        }
    }

    return false;
    
}

/* 
 *  Definition
 *  
 *      dp[k][i][j] means:
 *  
 *         a) s1[i] start from 'i'
 *         b) s2[j] start from 'j'
 *         c) 'k' is the length of substring
 *  
 *  Initialization     
 *  
 *      dp[1][i][j] = (s1[i] == s2[j] ? true : false)
 *  
 *  Formula
 *  
 *      same as the above recursive method idea
 *  
 *      dp[k][i][j] = 
 *          dp[divk][i][j] && dp[k-divk][i+divk][j+divk] ||
 *          dp[divk][i][j+k-divk] && dp[k-divk][i+divk][j]
 *  
 *      `divk` mean split the k to two parts, so 0 <= divk <= k;
*/
bool isScramble_dp(string s1, string s2) {

    if (s1.size()!= s2.size() || s1.size()==0 || s2.size()==0) {
        return false;
    }
    if (s1 == s2){
        return true;
    }

    const int len = s1.size();    
    
    // dp[len+1][len][len]
    vector< vector< vector<bool> > > dp(len+1, vector< vector<bool> >(len, vector<bool>(len) ) );
   
    // ignor the k=0, just for readable code.

    // initialization k=1
    for (int i=0; i<len; i++){
        for (int j=0; j<len; j++) {
            dp[1][i][j] = (s1[i] == s2[j]);
        }
    } 
    // start from k=2 to len, O(n^4) loop. 
    for (int k=2; k<=len; k++){
        for (int i=0; i<len-k+1; i++){
            for (int j=0; j<len-k+1; j++){
                dp[k][i][j] = false;
                for (int divk = 1; divk < k && dp[k][i][j]==false; divk++){
                    dp[k][i][j] = ( dp[divk][i][j] && dp[k-divk][i+divk][j+divk] ) ||
                                  ( dp[divk][i][j+k-divk] && dp[k-divk][i+divk][j] );
                }
            }
        }
    }
    
    return dp[len][0][0];
}

bool isScramble(string s1, string s2) {

    srand(time(0));

    if (random()%2) {
        cout << "---- recursion ---" << endl;
        return isScramble_recursion(s1, s2);
    }
    cout << "---- dynamic programming ---" << endl;
    return isScramble_dp(s1, s2);
}

int main(int argc, char** argv)
{
    string s1="great", s2="rgtae";
    if (argc>2){
        s1 = argv[1];
        s2 = argv[2];
    }
    cout << s1 << ", " << s2 << endl;
    cout << isScramble(s1, s2) << endl;
    return 0;
}
