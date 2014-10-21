// Source : https://oj.leetcode.com/problems/interleaving-string/
// Author : Hao Chen
// Date   : 2014-08-27

/********************************************************************************** 
* 
* Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
* 
* For example,
* Given:
* s1 = "aabcc",
* s2 = "dbbca",
* 
* When s3 = "aadbbcbcac", return true.
* When s3 = "aadbbbaccc", return false.
* 
*               
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Considering:

    s1 = a1, a2 ........a(i-1), ai
    s2 = b1, b2, .......b(j-1), bj
    s3 = c1, c3, .......c(i+j-1), c(i+j)


Defined 
    
    match[i][j]  means   s1[0..i] and s2[0..j] is matched S3[0..i+j]

    So, if ai == c(i+j), then match[i][j] = match[i-1][j], which means

        s1 = a1, a2 ........a(i-1)
        s2 = b1, b2, .......b(j-1), bj
        s3 = c1, c3, .......c(i+j-1)

    Same, if bj = c(i+j), then match[i][j] = match[i][j-1];

Formula:

    Match[i][j] = 
        (s3[i+j-1] == s1[i]) && match[i-1][j] || 
        (s3[i+j-1] == s2[j]) && match[i][j-1]

Initialization:

    i=0 && j=0, match[0][0] = true;

    i=0,   s3[j] == s2[j], match[0][j] |= match[0][j-1]
           s3[j] != s2[j], match[0][j] = false;

    j=0,   s3[i] == s1[i], match[i][0] |= match[i-1][0]
           s3[i] != s1[i], Match[i][0] = false;

*/




//Dynamic Programming
bool isInterleave(string s1, string s2, string s3) {
    
    if (s1.size() + s2.size() != s3.size()) {
        return false;
    }

    vector< vector<int> > match(s1.size()+1, vector<int>(s2.size()+1, false) );

    match[0][0] = true;
    for(int i=1; i<=s1.size(); i++) {
        if (s1[i-1] == s3[i-1] ) {
            match[i][0] = true;
        }else{
            break;
        }
    }
    for(int i=1; i<=s2.size(); i++) {
        if (s2[i-1] == s3[i-1] ) {
            match[0][i] = true;
        }else{
            break;
        }
    }

    
    for(int i=1; i<=s1.size(); i++) {
        for(int j=1; j<=s2.size(); j++) {
            if (s1[i-1] == s3[i+j-1]) {
                match[i][j] = match[i-1][j] || match[i][j];
            }
            if (s2[j-1] == s3[i+j-1]) {
                match[i][j] = match[i][j-1] || match[i][j];
            }
        }
    }
    return match[s1.size()][s2.size()];
}

//Time Limit Exceeded
bool isInterleave_dfs(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) {
        return false;
    }

    const char *p1 = s1.c_str(), *p2 = s2.c_str(), *p3 = s3.c_str();
    for (; *p3 != '\0'; p3++){
        if (*p3 == *p1 && *p3!=*p2) {
            p1++;
        }else if ( *p3 == *p2 && *p3 != *p1) {
            p2++;
        }else if (*p3==*p1 && *p3 ==*p2) {
            if (isInterleave(p1+1, p2, p3+1) == false){
                return isInterleave(p1, p2+1, p3+1);
            }
            return true;
        }else{
            return false;
        }
    }
    return ( *p1 =='\0' && *p2 =='\0' && *p3 =='\0' );
}

#define TEST(s1, s2, s3) cout << s1 << ", " << s2 << " = " << s3 << " : " << isInterleave(s1,s2,s3) << endl;
int main(int argc, char**argv)
{
    string s1=  "aabcc", s2 = "dbbca";
    TEST(s1,s2, "aadbbcbcac");
    TEST(s1,s2, "aadbbbaccc");

    s1="c"; s2="ca";
    TEST(s1, s2, "cca");
    TEST(s1, s2, "cac");

    s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
    s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
    string s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
    TEST(s1, s2, s3);
    
    return 0;
}
