// Source : https://leetcode.com/problems/ugly-number-ii/
// Author : Hao Chen
// Date   : 2015-10-21

/*************************************************************************************** 
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For 
 * example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 * 
 * Note that 1 is typically treated as an ugly number.
 * 
 *   The naive approach is to call isUgly for every number until you reach the nth one. 
 * Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
 *
 *   An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
 *
 *   The key is how to maintain the order of the ugly numbers. Try a similar approach 
 * of merging from three sorted lists: L1, L2, and L3.
 *
 *   Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 
 * * 5).
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 *               
 ***************************************************************************************/

class Solution {
public:

    int min(int a, int b) {
        return a < b ? a:b;
    }
    
    int min(int a, int b, int c) {
        return min( min(a, b),  c);
    }

    //  
    // The idea is we generate the ugly number instead of checking every number.
    //
    // To generate the next ugly number, we can use the existed ugly numbers to multipy 2,3,5,
    // and get the minimal one.
    //
    //     Let's start from the first ugly number - [1]
    //
    //        [1]  next = min( 1*2=2, 1*3=3, 1*5=5) = 2
    //
    //     Now we have [1,2], we can see, only the second one need be multipied by 2
    //     but both 3 and 5 still need be multipied by first one. So:
    // 
    //        [1,2]  next = min(2*2=4, 1*3=3, 1*5=5) = 3
    //
    //     Now we have [1,2,3], we can see the second one need be mulityped by 2 and 3,
    //     but the 5 still needs be multipied by first one. So:
    //
    //        [1,2,3]  next = min (2*2, 2*3, 1*5) = 4
    //
    //     and so on...
    //
    // So, we can see we need to maintain three indics in ugly number list, 
    // each one represents the place need be mulipied by 2,3,5.
    //
    // And we increase the index who's multiplication is the minimal. 
    //
    
    int nthUglyNumber01(int n) {
            
        int i=0, j=0, k=0;
        vector<int> v(1,1);
        
        while(v.size() < n){
            int next = min(v[i]*2, v[j]*3, v[k]*5);
            if (next == v[i]*2) i++;
            if (next == v[j]*3) j++;
            if (next == v[k]*5) k++;
            v.push_back(next);
        }
        return v.back();
    }
    
    // This version just uses the static variable to cache 
    // the 3 indics and the ugly number list
    int nthUglyNumber02(int n) {
            
        static int i=0, j=0, k=0;
        static vector<int> v(1,1);
    
        if (v.size()>=n) return v[n-1];
        
        while(v.size() < n){
            int next = min(v[i]*2, v[j]*3, v[k]*5);
            if (next == v[i]*2) i++;
            if (next == v[j]*3) j++;
            if (next == v[k]*5) k++;
            v.push_back(next);
        }
        return v.back();
    }
    
    int nthUglyNumber(int n) {
        return nthUglyNumber02(n); // 4ms-8ms
        return nthUglyNumber01(n); // 28ms
    }
};
