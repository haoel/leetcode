"""
Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.
Given two positive integers left and right represented as strings, 
return the number of super-palindromes integers in the inclusive range [left, right].
"""

class Solution:
    def superpalindromesInRange(self, left: str, right: str) -> int:
        pals = list(range(1, 10))
        for i in range(1, 10000):
            s = str(i)
            pals.append(int(s + s[::-1]))
            for j in range(10):
                pals.append(int(s + str(j) + s[::-1]));
        pals.sort()
        left = int(sqrt(int(left)))
        right = int(sqrt(int(right)))
        start = bisect_left(pals, left)
        end = bisect_right(pals, right)
        res = 0;
        for i in range(start, end):
            t = str(pals[i] ** 2)
            if t == t[::-1]:
                res += 1
        return res