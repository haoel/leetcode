# Method 1: find the greatest common divisor using iteration

def hasGroupsSizeX(self, deck):
    if len(deck) < 2: return False
    vals = collections.Counter(deck).values()
    for n in range(2, max(vals) + 1):
        if all(v % n == 0 for v in vals): return True
    return False

# Method 2: find the greatest common divisor using reduce
# Time complexity: O(n)
def hasGroupsSizeX(self, deck):
    from functools import reduce
    if len(deck) < 2: return False
    vals = collections.Counter(deck).values()
    def gcd(a, b):
        while b: a, b = b, a % b
        return a
    return reduce(gcd, vals)