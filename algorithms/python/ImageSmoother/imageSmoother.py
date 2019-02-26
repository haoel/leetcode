def imageSmoother(self, M):
    from copy import deepcopy
    
    if not M or not M[0]: return [[]]
    row, col = len(M), len(M[0])
    res = deepcopy(M)
    for x in range(row):
        for y in range(col):
            temp = [M[i][j] for i in [x - 1, x, x + 1] for j in [y - 1, y, y + 1] if \
                    0 <= i < row and 0 <= j < col]
            res[x][y] = sum(temp) // len(temp)
            
    return res