// Source : https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
// Author : Hao Chen
// Date   : 2016-09-08

/*************************************************************************************** 
 *
 * Find the length of the longest substring T of a given string (consists of lowercase 
 * letters only) such that every character in T appears no less than k times.
 * 
 * Example 1:
 * 
 * Input:
 * s = "aaabb", k = 3
 * 
 * Output:
 * 3
 * 
 * The longest substring is "aaa", as 'a' is repeated 3 times.
 * 
 * Example 2:
 * 
 * Input:
 * s = "ababbc", k = 2
 * 
 * Output:
 * 5
 * 
 * The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 
 * times.
 ***************************************************************************************/

const int NO_OF_CHARS = 256;

/* if every character appears at least k times, the whole string is ok. 
 * Otherwise split by a least frequent character.
 * 
 * Because it will always be too infrequent and thus can't be part of any ok substring
 * and make the most out of the splits.
 */


class Solution {
public:
    int longestSubstring(string s, int k) {
        
        //deal with edge cases
        if (s.size() == 0 || s.size() < k) return 0;
        if (k==1) return s.size();

        //declare a map for every char's counter
        int count[NO_OF_CHARS];
        memset(count , 0, sizeof(count));
        
        //counting every char
        for (char ch : s) {
            count[ch]++;
        }
        
        int i=0;
        for ( i=0; i<NO_OF_CHARS; i++) {
            if (count[i] !=0 && count[i] < k) break;
        }
        //all of the chars meet the requirement
        if ( i >= NO_OF_CHARS ) return s.size();
        
        // find the most infrequent char
        char least = 0;
        for (int c = 0; c < NO_OF_CHARS; c++) {
            if (count[c] == 0) continue;
            if (least == 0) {
                least = c;
            } else if ( count[c] < count[least]) {
                least = c;
            }
        }
        
        //split the string and run them recursively
        vector<string> subs;
        split(s, least, subs);
        
        int res = 0;
        for (string str: subs) {
            res = max(res, longestSubstring(str, k));
        }
        return res;
        return 0;
    }
    
private:
    
    inline int max(int x, int y) { return x>y? x:y; }
    
    inline void split(const string &s, char delim, vector<string> &elems) {
        stringstream ss;
        ss.str(s);
        string item;
        while (getline(ss, item, delim)) {
            cout << item << endl;
            elems.push_back(item);
        }
    }


    inline vector<string> split(const string &s, char delim) {
        vector<string> elems;
        split(s, delim, elems);
        return elems;
    }
};
