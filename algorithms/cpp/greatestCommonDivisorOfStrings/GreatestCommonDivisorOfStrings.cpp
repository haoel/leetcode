// Source : https://leetcode.com/problems/greatest-common-divisor-of-strings/
// Author : Hao Chen
// Date   : 2020-07-19

/***************************************************************************************************** 
 *
 * For strings S and T, we say "T divides S" if and only if S = T + ... + T  (T concatenated with 
 * itself 1 or more times)
 * 
 * Return the largest string X such that X divides str1 and X divides str2.
 * 
 * Example 1:
 * 
 * Input: str1 = "ABCABC", str2 = "ABC"
 * Output: "ABC"
 * 
 * Example 2:
 * 
 * Input: str1 = "ABABAB", str2 = "ABAB"
 * Output: "AB"
 * 
 * Example 3:
 * 
 * Input: str1 = "LEET", str2 = "CODE"
 * Output: ""
 * 
 * Note:
 * 
 * 	1 <= str1.length <= 1000
 * 	1 <= str2.length <= 1000
 * 	str1[i] and str2[i] are English uppercase letters.
 ******************************************************************************************************/

class Solution {
private:


    // Euclidean algorithm
    // https://en.wikipedia.org/wiki/Euclidean_algorithm
    // recursive way
    int findGCD_r(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    // non-recursive way
    int findGCD(int a, int b) {
        int t = 1;
        while(t != 0) {
            t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    bool isStrRepeatByLen(string& s, int len) {
        if (s.size() == len) return true;
        if (s.size() % len != 0 ) return false;
        for (int l=0; l<len; l++) {
            for (int i=1; i<s.size()/len; i++) {
                if (s[l] != s[i*len+l]) return false;
            }
        }
        return true;
    }

    bool strPrefixComp(string& s1, string &s2, int len){
        for(int i=0; i<len; i++) {
            if (s1[i] != s2[i]) return false;
        }
        return true;
    }
public:
    string gcdOfStrings(string s1, string s2) {

        int gcd = findGCD(s1.size(), s2.size());

        if (strPrefixComp(s1, s2, gcd) &&
            isStrRepeatByLen(s1, gcd)&&
            isStrRepeatByLen(s2, gcd) ){
            return s2.substr(0,gcd);
        }

        return "";
    }
};
