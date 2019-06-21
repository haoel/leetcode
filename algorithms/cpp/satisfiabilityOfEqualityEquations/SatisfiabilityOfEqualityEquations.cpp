// Source : https://leetcode.com/problems/satisfiability-of-equality-equations/
// Author : Hao Chen
// Date   : 2019-03-25

/***************************************************************************************************** 
 *
 * Given an array equations of strings that represent relationships between variables, each string 
 * equations[i] has length 4 and takes one of two different forms: "a==b" or "a!=b".  Here, a and b 
 * are lowercase letters (not necessarily different) that represent one-letter variable names.
 * 
 * Return true if and only if it is possible to assign integers to variable names so as to satisfy all 
 * the given equations.
 * 
 * Example 1:
 * 
 * Input: ["a==b","b!=a"]
 * Output: false
 * Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the 
 * second.  There is no way to assign the variables to satisfy both equations.
 * 
 * Example 2:
 * 
 * Input: ["b==a","a==b"]
 * Output: true
 * Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
 * 
 * Example 3:
 * 
 * Input: ["a==b","b==c","a==c"]
 * Output: true
 * 
 * Example 4:
 * 
 * Input: ["a==b","b!=c","c==a"]
 * Output: false
 * 
 * Example 5:
 * 
 * Input: ["c==c","b==d","x!=z"]
 * Output: true
 * 
 * Note:
 * 
 * 	1 <= equations.length <= 500
 * 	equations[i].length == 4
 * 	equations[i][0] and equations[i][3] are lowercase letters
 * 	equations[i][1] is either '=' or '!'
 * 	equations[i][2] is '='
 * 
 ******************************************************************************************************/


class Solution {
private:
    map<char, char>  eq_map; // the table store the equivalent relationship
    void init() {
        for (char ch='a'; ch<='z'; ch++) {
            eq_map[ch] = ch;
        }
    }
public:
    Solution() {
        init();
    }
    
    // find the tail node, 
    // if a == b == c == d, find(a) would return d;
    //                      find(b) would return d;
    char find(char ch) {
        while(ch != eq_map[ch]) {
            ch = eq_map[ch];
        }
        return ch;
    }
    
    //join x equivalent chain with y equivalent chain
    void join(char x, char y) {
        char tx = find(x);
        char ty = find(y);
        if (tx != ty) { 
            eq_map[tx] = ty;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        for (auto e : equations ) {
            if (e[1] == '=' && e[0] != e[3]) { // equal
                join(e[0], e[3]);
            }
        }
        for (auto e : equations) {
            if (e[1] == '!' && (e[0] == e[3] || find(e[0]) == find(e[3]) ) ) { 
                return false;
            }
        }
        return true;
    }
};


