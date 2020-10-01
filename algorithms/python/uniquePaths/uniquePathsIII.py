# 980. Unique Paths III
# On a 2-dimensional grid, there are 4 types of squares:

# 1 represents the starting square.  There is exactly one starting square.
# 2 represents the ending square.  There is exactly one ending square.
# 0 represents empty squares we can walk over.
# -1 represents obstacles that we cannot walk over.
# Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

# Example 1:

# Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
# Output: 2
# Explanation: We have the following two paths: 
# 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
# 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
# Example 2:

# Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
# Output: 4
# Explanation: We have the following four paths: 
# 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
# 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
# 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
# 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
# Example 3:

# Input: [[0,1],[2,0]]
# Output: 0
# Explanation: 
# There is no path that walks over every empty square exactly once.
# Note that the starting and ending square can be anywhere in the grid.
 

# Note:

# 1 <= grid.length * grid[0].length <= 20

class Solution:
    ans = 0
    def findPathNum(self, i, j, grid: List[List[int]], curLen, pLen)->None:
        if(grid[i][j]==2):
            if(pLen-1==curLen):
                self.ans+=1
            return
        elif (grid[i][j]==-1):
            return
        curLen+=1
        grid[i][j]=-1
        if(i-1>=0):
            self.findPathNum(i-1, j, grid, curLen, pLen)
        if(j-1>=0):
            self.findPathNum(i, j-1, grid, curLen, pLen)
        if(i+1<len(grid)):
            self.findPathNum(i+1, j, grid, curLen, pLen)
        if(j+1<len(grid[0])):
            self.findPathNum(i, j+1, grid, curLen, pLen)
        grid[i][j]=0
        
            
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        pathLen = 0
        start = (0, 0)
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if(grid[i][j]!=-1):
                    pathLen+=1
                    if(grid[i][j]==1):
                        start = (i, j)
        self.findPathNum(start[0], start[1], grid, 0, pathLen)
        return self.ans
        