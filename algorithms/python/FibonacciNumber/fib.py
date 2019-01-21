"""
Method 1: iterative:
"""
def fib1(self, N):
    if N <= 1: return N
    a, b = 0, 1
    for _ in range(2, N + 1):
        a, b = b, a + b
    return b
    
"""
Method 2: recursive without memorization:
"""
def fib2(self, N):
    if N <= 1: return N
    return self.fib(N - 1) + self.fib(N - 2)

"""
Method 3: recursive with memorization
"""
def fib3(self, N):
    memo = {0:0, 1:1}
    def helper(n):
        if n not in memo:
            memo[n] = helper(n - 1) + helper(n - 2)
        return memo[n]
    return helper(N)