# Method 1: Binary Search on each row, if the first element of the row is already bigger than target, then skip
# Time Complexity: O(mlogn)
def searchMatrix1(self, matrix, target):
    def helper(low, high, row):
        while low <= high:
            mid = (low + high) // 2
            if matrix[row][mid] < target: low = mid + 1
            elif matrix[row][mid] > target: high = mid - 1
            else: return True
        return False
    
    if not matrix or not matrix[0]: return False
    for i in range(len(matrix)):
        if matrix[i][0] > target: return False
        elif matrix[i][0] == target: return True
        if helper(0, len(matrix[i]) - 1, i): return True
    return False

# Method 2: compare the element with top-right corner, and reduce the search range
# Time complexity: O(m + n)
def searchMatrix2(self, matrix, target):
    if not matrix or not matrix[0]: return False
    row, col = 0, len(matrix[0]) - 1
    while row < len(matrix) and col >= 0:
        if matrix[row][col] > target: col -= 1
        elif matrix[row][col] < target: row += 1
        else: return True
    return False