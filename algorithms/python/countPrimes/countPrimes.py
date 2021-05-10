'''
* 204. Count Primes
* Count the number of prime numbers less than a non-negative number, n.
'''

class Solution:
    def countPrimes(self, n: int) -> int:
        primes = [True] * n
        res = 0
        for i in range(2, n):
            if primes[i]:
                res += 1
                for j in range(2, n):
                    if j * i >= n: 
                        break
                    primes[i * j] = False
        return res