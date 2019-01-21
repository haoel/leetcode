# Method 1: straight forward solution, use a set to track if there is a cycle

def isHappy1(self, n):
    if n <= 0: return False
    s = set()
    while n not in s:
        s.add(n)
        n = sum([int(i) ** 2 for i in str(n)])
        if n == 1: return True
    return False

# Method 2: using a slow and fast pointer to determine cycle (like in linked list)
# No extra space needed
def isHappy2(self, n):
    """
    :type n: int
    :rtype: bool
    """
    if n <= 0: return False
    def helper(n):
        res = 0
        while n:
            res += (n % 10) ** 2
            n = n // 10
        return res
    
    slow = fast = n
    while True:
        slow = helper(slow)
        fast = helper(helper(fast))
        if slow == 1: return True
        if slow == fast: break
    return False