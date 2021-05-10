// Source : https://leetcode.com/problems/maximize-number-of-nice-divisors/
// Author : Hao Chen
// Date   : 2021-03-28

/***************************************************************************************************** 
 *
 * You are given a positive integer primeFactors. You are asked to construct a positive integer n that 
 * satisfies the following conditions:
 * 
 *   The number of prime factors of n (not necessarily distinct) is at most primeFactors.
 *   The number of nice divisors of n is maximized. Note that a divisor of n is nice if it is 
 * divisible by every prime factor of n. For example, if n = 12, then its prime factors are [2,2,3], 
 * then 6 and 12 are nice divisors, while 3 and 4 are not.
 * 
 * Return the number of nice divisors of n. Since that number can be too large, return it modulo 10^9 
 * + 7.
 * 
 * Note that a prime number is a natural number greater than 1 that is not a product of two smaller 
 * natural numbers. The prime factors of a number n is a list of prime numbers such that their product 
 * equals n.
 * 
 * Example 1:
 * 
 * Input: primeFactors = 5
 * Output: 6
 * Explanation: 200 is a valid value of n.
 * It has 5 prime factors: [2,2,2,5,5], and it has 6 nice divisors: [10,20,40,50,100,200].
 * There is not other value of n that has at most 5 prime factors and more nice divisors.
 * 
 * Example 2:
 * 
 * Input: primeFactors = 8
 * Output: 18
 * 
 * Constraints:
 * 
 * 	1 <= primeFactors <= 10^9
 ******************************************************************************************************/

/*
    considering `primeFactors = 5`
    
    So, we can have the following options:
    1) [2,3,5,7,11] - all of factors are different, then we only can have 1 nice divisor
    2) [2,2,3,5,7] - we can have 2*1*1*1 = 2 nice divisors: 2*3*5*7 and 2*2*3*5*7
    3) [2,2,3,3,5] - we can have 2*2*1 = 4 nice divisors: 2*3*5， 2*2*3*5， 2*3*3*5， 2*2*3*3*5
    4) [2,2,3,3,3] - we can have 2*3 = 6 nice divisors
    5）[2,2,2,2,3] - we can have 4*1 =4 nice divisors: 2*3, 2*2*3, 2*2*2*3, 2*2*2*2*3
    6) [2,2,2,2,2] - we can have 5 nice divisors: 2, 2*2, 2*2*2, 2*2*2*2, 2*2*2*2*2
    
    So, we can see we must have some duplicated factors.
    
    And what is the best number of duplication ?
    primeFactors = 1, then 1        - example: [2]
    primeFactors = 2, then 2        - example: [2,2]
    primeFactors = 3, then 3        - example: [5,5,5]
    primeFactors = 4, then 4 = 2*2  - example: [2,2,5,5])
    primeFactors = 5, then 5 = 2*3  - example: [3,3,3,5,5])
    primeFactors = 5, then 6 = 3*3  - example: [3,3,3,5,5,5])
    primeFactors = 7, then 3*4 = 12 - example: [3,3,3,5,5,5,5])
    primeFactors = 8, then 3*3*2 = 18  whcih > (2*2*2*2,  2*4*2, 3*5)
    primeFactors = 9, then 3*3*3 = 27  
    primeFactors = 10, then 3*3*4 = 36
    
    So, we can see the '3' & '4' are  specifial,
    - most of case, we can be greedy for `3`
    - but if the final rest is 4, then we need take 4.
    
 */

const int mod = 1000000007;

class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
        return maxNiceDivisors_03(primeFactors);
        return maxNiceDivisors_02(primeFactors); //TLE
        return maxNiceDivisors_01(primeFactors); //TLE
    }
    
    int maxNiceDivisors_01(int primeFactors) {
        int result = 1;
        while ( primeFactors > 4 ) {
            primeFactors -= 3;
            result = (result * 3l) % mod;
        }
        result = (result * (long)primeFactors) % mod;
        return result;
    }
    
    int maxNiceDivisors_02(int primeFactors) {
        if (primeFactors <= 4 ) return primeFactors;
        int result = 1;
        for (int i = 4; i > 0; i-- ){
            if ((primeFactors - i) % 3 == 0){ 
                result = i;
                primeFactors -= i;
                // now, `primeFactors` is 3 times - 3X
                // we need convert 3X to 3^X
                for (int x = primeFactors/3; x > 0; x-- ) {
                    result = (result * 3l) % mod;
                }
                break;
            }
        }
        return result;
    }
    
    int pow3(int x) {
        long  result = 1;
        long  factor = 3;
        while(x > 0) {
            if (x & 1) {
                result = (result * factor) % mod;
                
            }
            factor *= factor;
            factor %= mod;
            x /= 2;
        }
        return result % mod;
    }
    
    int maxNiceDivisors_03(int primeFactors) {
        
        if (primeFactors <= 4 ) return primeFactors;
        int result = 1;
        for (int i = 4; i > 0; i-- ){
            if ((primeFactors - i) % 3 == 0){ 
                primeFactors -= i;
                // now, `primeFactors` is 3 times - 3X
                // we need convert 3X to 3^X
                int x = primeFactors / 3;
                result = (long(i) * pow3(x)) % mod;
                break;
            }
        }
        return result;
    }
};
