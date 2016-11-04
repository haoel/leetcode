// Source : https://leetcode.com/problems/integer-replacement/
// Author : Hao Chen
// Date   : 2016-11-04

/*************************************************************************************** 
 *
 * Given a positive integer n and you can do operations as follow:
 * 
 * If n is even, replace n with n/2.
 * If n is odd, you can replace n with either n + 1 or n - 1.
 * 
 * What is the minimum number of replacements needed for n to become 1?
 * 
 * Example 1:
 * 
 * Input:
 * 8
 * 
 * Output:
 * 3
 * 
 * Explanation:
 * 8 -> 4 -> 2 -> 1
 * 
 * Example 2:
 * 
 * Input:
 * 7
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * 7 -> 8 -> 4 -> 2 -> 1
 * or
 * 7 -> 6 -> 3 -> 2 -> 1
 ***************************************************************************************/

class Solution {
public:


    int integerReplacement_recursion(int n) {
        if ( n <= 1) return 0; // recursive exited point
        if ( n == INT_MAX ) return 32; // special case to avoid integer overflow.
        if ( n % 2 == 0 ) return integerReplacement(n/2) + 1;
        return min( integerReplacement(n+1), integerReplacement(n-1) ) + 1;
    }
    
    int integerReplacement_recursionWithCache(int n) {
        static unordered_map<int, int> cache;
        //if hitted the cache, just return the result
        if (cache.find(n) != cache.end()) return cache[n];
        
        int result;
        if ( n <= 1) return 0; // recursive exited point
        if ( n == INT_MAX ) return 32; // special case to avoid integer overflow.
        if ( n % 2 == 0 ) result = integerReplacement(n/2) + 1;
        else result = min( integerReplacement(n+1), integerReplacement(n-1) ) + 1;
        
        //add into cache
        cache[n] = result;
        return result;
    }
    
    int integerReplacement(int n) {
        return integerReplacement_recursionWithCache(n);
    }
};
