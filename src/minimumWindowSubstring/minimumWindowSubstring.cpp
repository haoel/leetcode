// Source : https://oj.leetcode.com/problems/minimum-window-substring/
// Author : Hao Chen
// Date   : 2014-07-22

/********************************************************************************** 
* 
* Given a string S and a string T, find the minimum window in S which will 
* contain all the characters in T in complexity O(n).
* 
* For example,
* S = "ADOBECODEBANC"
* T = "ABC"
* 
* Minimum window is "BANC".
* 
* Note:
*
* > If there is no such window in S that covers all characters in T, 
*   return the emtpy string "".
* 
* > If there are multiple such windows, you are guaranteed that there 
*   will always be only one unique minimum window in S.
* 
*               
**********************************************************************************/

#include <string.h>
#include <iostream>
#include <string>
using namespace std;

#define INT_MAX      2147483647

string minWindow(string S, string T) {
    string win;
    if (S.size()<=0 || T.size()<=0 || T.size() > S.size()) return win;
    /*
     * Declare two "hash map" for ASCII chars
     *   f[]: represents the char found in string S
     *   m[]: stores the chars in string T
     */    
    const int MAX_CHARS = 256;
    int f[MAX_CHARS], m[MAX_CHARS];
    
    const int NOT_EXISTED   = -1;
    const int NOT_FOUND     =  0;
    memset(m, NOT_EXISTED, sizeof(m));
    memset(f, NOT_EXISTED, sizeof(f));

    /* 
     *  Go through the T, and inital the m[] and f[] 
     *  Notes: a same char can be appeared multiple times.
     */
    for(int i=0; i<T.size(); i++) {
        m[T[i]]==NOT_EXISTED ? m[T[i]]=1 : m[T[i]]++ ; 
        f[T[i]] = NOT_FOUND; 
    }

    int start =-1;
    int winSize = INT_MAX;
    int letterFound = 0;
    int begin = 0;
    for(int i=0; i<S.size(); i++) {
        /* if S[i] is existed in T*/ 
        if ( m[S[i]] != NOT_EXISTED ){
            char ch = S[i];
            f[ch]++;

            /* if one char has been found enough times, then do not do letterFound++ */
            if (f[ch] <= m[ch]) {
                letterFound++;
            }
            if ( letterFound >= T.size() ) {
                /* 
                 * Find the beginning of the window
                 * 1) f[S[begin]] == NOT_EXISTED  ===> the char at the `begin` is not in T
                 * 2) f[S[begin]] > m[S[begin]]   ===> a same char appeared more than excepted.
                 */
                while ( f[S[begin]] == NOT_EXISTED || f[S[begin]] > m[S[begin]] ) { 
                    if ( f[S[begin]] > m[S[begin]] ) {
                        f[S[begin]]--;
                    }   
                    begin++;
                }
                /* Calculate the minimized window size */
                if(winSize > i - begin + 1){
                    start = begin;
                    winSize = i - begin + 1;
                }     
                
            }
            
        }
    }

    if (start>=0 && winSize>0) {
        win = S.substr(start, winSize);
    }
    return win;
}


int main(int argc, char**argv)
{
    string S = "ADOBECODEBANC";
    string T = "ABC";
    if (argc>2){
        S = argv[1];
        T = argv[2];
    }
    cout << "S = \"" << S << "\"  T=\"" << T << "\"" <<endl;
    cout << minWindow(S, T) << endl;
    return 0;
}

