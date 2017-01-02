// Source : https://leetcode.com/problems/super-ugly-number/
// Author : Hao Chen
// Date   : 2017-01-02

/*************************************************************************************** 
 *
 * Write a program to find the nth super ugly number.
 * 
 *     Super ugly numbers are positive numbers whose all prime factors are in the given 
 * prime list
 *     primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32]
 *  is the sequence of the first 12 super ugly numbers given primes
 *     = [2, 7, 13, 19] of size 4.
 * 
 *     Note:
 *     (1) 1 is a super ugly number for any given primes.
 *     (2) The given numbers in primes are in ascending order.
 *     (3) 0 k ≤ 100, 0 n ≤ 106, 0 primes[i] 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test 
 * cases.
 ***************************************************************************************/

// As the solution we have for the ugly number II problem
//
//    int nthUglyNumber(int n) {
//
//        int i=0, j=0, k=0;
//        vector<int> ugly(1,1);
//
//        while(ugly.size() < n){
//            int next = min(ugly[i]*2, ugly[j]*3, ugly[k]*5);
//            if (next == ugly[i]*2) i++;
//            if (next == ugly[j]*3) j++;
//            if (next == ugly[k]*5) k++;
//            ugly.push_back(next);
//        }
//        return ugly.back();
//    }
//
// The logic of solution is exacly same for both., except that instead of 3 numbers you have k numbers to consider. 
//
// 
//
class Solution {
  
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(1, 1);
        int len = primes.size();
        vector<int> pos(len, 0);
        
        while( ugly.size() < n ) {
            int next = INT_MAX;
            for(int i=0; i<len; i++) {
                next = min(next, ugly[pos[i]] * primes[i]);
            }
            for(int i=0; i<len; i++) {
                if (next == ugly[pos[i]] * primes[i]) {
                    pos[i]++;
                }
            }
            ugly.push_back(next);
        }
        return ugly.back();
    }
    

};
