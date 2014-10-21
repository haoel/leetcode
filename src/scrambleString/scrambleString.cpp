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

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isScramble(string s1, string s2) {

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
        if ( isScramble(s1.substr(0,i), s2.substr(0,i)) && 
             isScramble(s1.substr(i, s1.size()-i), s2.substr(i, s2.size()-i)) ) {
            return true;
        }
        if ( isScramble(s1.substr(0,i), s2.substr(s2.size()-i, i)) && 
             isScramble(s1.substr(i, s1.size()-i), s2.substr(0, s2.size()-i)) ) {
            return true;
        }
    }

    return false;
    
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
