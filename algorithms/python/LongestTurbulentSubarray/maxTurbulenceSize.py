def maxTurbulenceSize(self, A):
    res = inc = dec = 1
    for i in range(1, len(A)):
        if A[i] > A[i - 1]:
            inc = dec + 1
            dec = 1
        elif A[i] < A[i - 1]:
            dec = inc + 1
            inc = 1
        else:
            inc = 1
            dec = 1
        res = max(res, max(inc, dec))
    return res