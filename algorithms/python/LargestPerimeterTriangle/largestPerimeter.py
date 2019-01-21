def largestPerimeter(self, A):
    A.sort()
    n = len(A)
    for i in range(1, len(A) - 1):
        if A[n - i - 2] + A[n - i - 1] > A[n - i]:
            return A[n - i - 2] + A[n - i - 1] + A[n - i]
    return 0