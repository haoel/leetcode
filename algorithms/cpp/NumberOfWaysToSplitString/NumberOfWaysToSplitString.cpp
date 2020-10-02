// Source : https://leetcode.com/problems/number-of-ways-to-split-a-string/
// Author : Sudesh Chaudhary
// Date   : 2020-10-01

/************************************************************************************************
*     Given a binary string s (a string consisting only of '0's and '1's), we can split s into 3 non-empty strings s1, s2, s3 (s1+   *      s2+ s3 = s).
*
*     Return the number of ways s can be split such that the number of characters '1' is the same in s1, s2, and s3.
*
*     Since the answer may be too large, return it modulo 10^9 + 7.
*
*     Example 1:
*
*     Input: s = "10101"
*     Output: 4
*     Explanation: There are four ways to split s in 3 parts where each part contain the same number of letters '1'.
*     "1|010|1"
*     "1|01|01"
*     "10|10|1"
*     "10|1|01"
*
*
*      Example 2:
*
*      Input: s = "1001"
*      Output: 0
*
*      Example 3:
*
*      Input: s = "0000"
*      Output: 3
*      Explanation: There are three ways to split s in 3 parts.
*      "0|0|00"
*      "0|00|0"
*      "00|0|0"
*
*      Example 4:
*
*      Input: s = "100100010100110"
*      Output: 12
***************************************************************************************************/

// solution->

// time O(n) space O(n)

#define mod (long long)(1e9+7)
#define ll long long
class Solution {
public:
    int numWays(string s) {

        int n = s.size();

        vector<int> pre(n),suf(n),last(n);
        int count=0;

        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                count++;
            }
            pre[i]=count;
        }

        // check if it can't be divided into three parts
        if(count%3!=0)
            return 0;

        int k  = count/3;
        count=0;
        int t=0;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='1')
                count++;
            suf[i]=count;
        }

        count=0;

        for(int i=n-1;i>=0;i--){

            if(suf[i]==k)
                count++;
            last[i]=count;
        }

        ll res=0;

        for(int i=0;i<n-1;i++){

            if(pre[i]==k){

                if(k!=0)
                    res= (res+last[i+1])%mod;
                else
                    res=(res+last[i+1]-1)%mod;
            }
        }

        return res;
    }
};
