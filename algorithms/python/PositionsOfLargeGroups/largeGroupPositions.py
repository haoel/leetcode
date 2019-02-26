def largeGroupPositions(self, S):
    res = []
    i = 0
    while i < len(S) - 2:
        if S[i] == S[i + 1] and S[i] == S[i + 2]:
            val = S[i]
            index = i
            while i < len(S) and S[i] == val:
                i += 1
            res.append([index, i - 1])
            i -= 1
        i += 1
    return res