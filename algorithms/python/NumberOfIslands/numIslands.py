def numIslands(self, grid):
    if not grid or not grid[0]: return 0
    row, col = len(grid), len(grid[0])
    self.visited = [[False for _ in range(col)] for _ in range(row)]
    
    def floodfill(i, j):
        if grid[i][j] == '1' and self.visited[i][j] == False:
            self.visited[i][j] = True
            if i > 0:
                floodfill(i - 1, j)
            if i < row - 1:
                floodfill(i + 1, j)
            if j > 0:
                floodfill(i, j - 1)
            if j < col - 1:
                floodfill(i, j + 1)
    
    res = 0
    for i in range(row):
        for j in range(col):
            if grid[i][j] == '1' and self.visited[i][j] == False:
                res += 1
                floodfill(i, j)
    return res