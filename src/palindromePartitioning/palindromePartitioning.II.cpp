// Source : https://oj.leetcode.com/problems/palindrome-partitioning-ii/
// Author : Hao Chen
// Date   : 2014-08-24

/********************************************************************************** 
* 
* Given a string s, partition s such that every substring of the partition is a palindrome.
* 
* Return the minimum cuts needed for a palindrome partitioning of s.
* 
* For example, given s = "aab",
* Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
* 
*               
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool isPalindrome(string &s, int start, int end);
void minCutHelper(string &s, int start, int steps, int& min );
int minCutHelper(string &s, int steps, int& minSteps );
int minCut_DP(string& s); 

int minCut(string s) {
    #define INT_MAX 2147483647
    if(s.size()<=1) return 0;

    int min = INT_MAX;
    
    //minCutHelper(s, 0, 0, min);
    //return min-1;

    //int m =  minCutHelper(s, 0, min);
    //return m-1;

    return minCut_DP(s);
}

/*
 *  Dynamic Programming
 *  -------------------
 *
 *  Define res[i] = the minimum cut from 0 to i in the string.
 *  The result w =e need eventually is res[s.size()-1].
 *  We know res[0]=0. Next we are looking for the optimal solution function f.
 *  
 *  For example, let s = "leet".
 *  
 *  f(0) = 0;  // minimum cut of str[0:0]="l", which is a palindrome, so not cut is needed.
 *  f(1) = 1; // str[0:1]="le" How to get 1? 
 *                   f(1) might be:  (1)   f(0)+1=1, the minimum cut before plus the current char.
 *                                   (2)   0, if str[0:1] is a palindrome  (here "le" is not )
 *  f(2) = 1; // str[0:2] = "lee" How to get 2?
 *                  f(2) might be:   (1)  f(1) + 1=2
 *                                   (2)  0, if str[0:2] is a palindrome (here "lee" is not)
 *                                   (3)  f(0) + 1,  if str[1:2] is a palindrome, yes! 
 *  f(3) = 2; // str[0:3] = "leet" How to get 2?
 *                  f(3) might be:   (1)  f(2) + 1=2
 *                                   (2)  0, if str[0:3] is a palindrome (here "leet" is not)
 *                                   (3)  f(0) + 1,  if str[1:3] is a palindrome (here "eet" is not)
 *                                   (4)  f(1) + 1,  if str[2:e] is a palindrome (here "et" is not)
 *  OK, output f(3) =2 as the result.
 *  
 *  So, the optimal function is:
 *  
 *  f(i) = min [  f(j)+1,  j=0..i-1   and str[j:i] is palindrome
 *                      0,   if str[0,i] is palindrome ]
 *  
 *  The above algorithm works well for the smaller test cases, however for the big cases, it still cannot pass.
 *  Why? The way we test the palindrome is time-consuming.
 *  
 *  Also using the similar DP idea, we can construct the look-up table before the main part above, 
 *  so that the palindrome testing becomes the looking up operation. The way we construct the table is also the idea of DP.
 *
 *  e.g.   mp[i][j]==true if str[i:j] is palindrome.
 *         mp[i][i]=true;
 *         mp[i][j] = true if str[i]==str[j] and (mp[i+1][j-1]==true or j-i<2 )  j-i<2 ensures the array boundary. 
 */


int minCut_DP(string& s) {
    vector<int>res(s.size(),0);
    bool mp[s.size()][s.size()];

    for (int i=s.size()-1;i>=0;i--){
        for (int j=i;j<s.size();j++){
            if ((s[i]==s[j]) && (j-i<2 || mp[i+1][j-1])){
                mp[i][j]=true;
            }else{
                mp[i][j]=false;
            }
        }
    }
    for (int i=0;i<s.size();i++){
        if (mp[0][i]){
            res[i]=0;
        }else{
            int ms = s.size();
            for (int j=0;j<i;j++){
                if (mp[j+1][i] && ms>res[j]+1 ) {
                    ms=res[j]+1;
                } 
            }
            res[i]=ms;
        }
    }
    return res[s.size()-1];
}

//More Optimized DFS -  Time Limit Exceeded
int minCutHelper(string &s, int steps, int& minSteps ) {

    // remove the steps if it's greater than minSteps 
    if (minSteps <= steps) {
        return -2;
    }
    // adding the cache
    static map<string, int> cache;
    if ( cache.find(s)!=cache.end() ){
        if (s.size()>0)
            cout << s << ":" << cache[s] << endl;
        return cache[s];
    }
    if (s.size()==0) {
        if (minSteps > steps){
            minSteps = steps;
        }
        cache[s] = 0;
        return 0;
    }


    int min = INT_MAX;
    string subs;
    int m; 
    for( int i=s.size()-1; i>=0; i-- ) {
        //remove the steps which greater than minSteps
        if ( i < s.size()-1 && minSteps - steps <= 1) {
            break;
        }
        if ( isPalindrome(s, 0, i) ){
            //if ( i == s.size()-1 ) {
            //    m = 1;
            //}else{
            subs = s.substr(i+1, s.size()-i-1);
            m = minCutHelper(subs, steps+1, minSteps) + 1;
            //}
            if (m < 0) continue;
            cache[subs] = m-1;
            if (min > m ){
                min = m;
            }
        }
    }
    return min;
}


//Optimized DFS -  Time Limit Exceeded
void minCutHelper(string &s, int start, int steps, int& min ) {

    if (start == s.size()) {
        if (steps < min) {
            min = steps;
            return;
        }
    }

    //GREED: find the biggest palindrome first
    for(int i=s.size()-1; i>=start; i--){
        //cut unnecessary DFS 
        if ( min > steps && isPalindrome(s, start, i)) {
            //if ( cache.find(i+1)==cache.end() ){
            minCutHelper(s, i+1, steps+1, min );
            //    cache[i+1] = true;
            //}
        }
    }
}

bool isPalindrome(string &s, int start, int end)  {  

    while(start < end)  {  
        if(s[start] != s[end]) { 

            return false;  
        }
        start++; end--;  
    }  

    return true;  
}  

//ababababababababababababcbabababababababababababa
//fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

int main(int argc, char** argv)
{
    string s("aab");
    if ( argc > 1 ){
        s = argv[1];
    }

    cout << s << " : " << minCut(s) << endl;

}
