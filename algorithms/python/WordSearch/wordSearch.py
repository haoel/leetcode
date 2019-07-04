'''
The basic idea is that to first loop through the board and find the first lettter in the word same as the current letter
a b c
d f g.

if we are going to find 'fgc' we will start checking at board[1][1] where f==f then using the back-tracking method
dfs to findout whether this entry point is able to match the whole word.
'''



class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        found = False
        row = len(board)
        col = len(board[0])
        visited = set()

        def dfs(i,j,wordFound):
            # print((i,j),wordFound)

            if board[i][j] != wordFound[0]:
                return False

            visited.add((i, j))
            if board[i][j] == wordFound:
                return True
            up = dfs(i-1,j,wordFound[1:]) if i-1 >=0 and (i-1,j) not in visited else False
            down = dfs(i+1,j,wordFound[1:]) if i+1 <row and (i+1,j) not in visited else False
            left = dfs(i,j-1,wordFound[1:]) if j-1 >= 0 and (i,j-1) not in visited else False
            right = dfs(i,j+1,wordFound[1:]) if j+1 < col and (i,j+1) not in visited else False

            if up or down or left or right:
                return True
            else:
                visited.remove((i,j))
                return False

        for i in range(row):
            for j in range(col):
                if board[i][j] == word[0]:
                    found = dfs(i,j,word)
                    visited.clear()
                    if found: return True



        return found