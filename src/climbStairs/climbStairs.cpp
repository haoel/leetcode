// Source : https://oj.leetcode.com/problems/climbing-stairs/
// Author : Hao Chen
// Date   : 2014-06-27

/********************************************************************************** 
* 
* You are climbing a stair case. It takes n steps to reach to the top.
* 
* Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
* 
*               
**********************************************************************************/

class Solution {
public:
    
    int climbStairs(int n) {
       if (n<=3) return n;
       int a[2]={2,3};
       for(int i=4; i<=n; i++){
           int t = a[0] + a[1];
           a[0] = a[1];
           a[1] = t;
       }
       return a[1];
    }
    //Time too long
    int climbStairs2(int n) {
        if (n<=3) return n;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};
