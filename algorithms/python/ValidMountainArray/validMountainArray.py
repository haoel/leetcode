# Method 1: using index find the max first, and then process

def validMountainArray(self, A):
    if len(A) < 3: return False
    index = A.index(max(A))
    if index == 0 or index == len(A) -1: return False
    for i in range(1, len(A)):
        if i <= index:
            if A[i] <= A[i - 1]: return False
        else:
            if A[i] >= A[i - 1]: return False
    return True


# Method 2: one pass, using two pointers trace from the begining and end
def validMountainArray(self, A):
    i, j = 0, len(A) - 1
    while i < len(A) - 1 and A[i] < A[i + 1]: i += 1
    while j > 0 and A[j - 1] > A[j]: j -= 1
    return 0 < i == j < len(A) - 1