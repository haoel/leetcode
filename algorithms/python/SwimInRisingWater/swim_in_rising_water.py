"""
Solution to LeetCode problem Swim in Rising Water (#778)
Difficulty: Hard

Explanation:
We are approaching the problem through Djikstras Algorith. Essentially a BFS but with a minimum heap. The neighbors that you are adding into the queue, you are only popping the minimum value neighbor. Amongst those popped value you are checking if that value is the max value seen so far. If it is, then you have found the solution.
"""
from heapq import heappush, heappop
from typing import List

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        src, dst = grid[0][0], grid[len(grid)-1][len(grid)-1]
        visited = set()
        heap_queue = [(src, 0, 0)]  # src, row, col
        output = 0
        directions = [(0, 1), (1, 0), (-1, 0), (0, -1)]
        while heap_queue:
            current, row, col = heappop(heap_queue)
            output = max(current, output)

            # if we already hit the destination, break out of the loop
            if current == dst:
                break

            for x, y in directions:
                dx, dy = row+x, col+y
                if self.check_bounds(dx, dy, grid) and (dx, dy) not in visited:
                    heappush(heap_queue, (grid[dx][dy], dx, dy))
                    visited.add((dx, dy))
        return output

    def check_bounds(self, r, c, grid) -> bool:
        if 0 <= r < len(grid[0]) and 0 <= c < len(grid):
            return True
        return False


if __name__ == "__main__":
    grid = [[0, 2], [1, 3]]
    print(Solution().swimInWater(grid))