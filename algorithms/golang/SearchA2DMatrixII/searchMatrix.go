func searchMatrix(matrix [][]int, target int) bool {
    rows := len(matrix)
    if rows <= 0 {
        return false
    }
    cols := len(matrix[0])
    
    i, j := rows-1, 0
    for i>=0 && j<cols {
        if(target == matrix[i][j]) {
            return true
        }
        if(target < matrix[i][j]) {
            i--
        }
        if(target > matrix[i][j]) {
            j++
        }
    }

    return false
}