"""
basic idea: find the index of smallest element in A, filp the list from that index, this makes the smallest element
comes to the first, then filp the whole list, to make smallest element goes to the tail. And then delete that element.

Do this step until all the smallest element comes to the tail, then just filp the whole list again, and we can get what we want
"""

def pancakeSort(self, A):
    res = []
    n = len(A)
    while A:
        smallest = A.index(min(A))
        res.append(smallest + 1)
        res.append(len(A))
        A = list(reversed(A[:smallest + 1])) + A[smallest + 1:]
        A.reverse()
        del A[-1]
    res.append(n)
    return res