// Source : https://leetcode.com/problems/count-primes/
// Author : Harvey Cao
// Date   : 2021-05-10

/********************************************************************************** 
* 204. Count Primes
* Count the number of prime numbers less than a non-negative number, n.
*               
**********************************************************************************/

/**
 * @param {number} n
 * @return {number}
 */
 var countPrimes = function(n) {
    const primes = new Array(n).fill(true);
    let res = 0;
    for (let i = 2; i < n; i++) {
        if (primes[i]) {
            res++;
            for (let j = i * i; j < n; j += i) primes[j] = false;
        }
    }
    return res;
};