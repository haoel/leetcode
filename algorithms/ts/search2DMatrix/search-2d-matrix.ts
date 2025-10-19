// Source : https://oj.leetcode.com/problems/search-a-2d-matrix/
// Author : Hao Chen
// Date   : 2014-06-23

/********************************************************************************** 
* 
* Write an efficient algorithm that searches for a value in an m x n matrix. 
* This matrix has the following properties:
* 
* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.
* 
* For example,
* 
* Consider the following matrix:
* 
* [
*   [1,   3,  5,  7],
*   [10, 11, 16, 20],
*   [23, 30, 34, 50]
* ]
* 
* Given target = 3, return true.
*               
**********************************************************************************/
function searchMatrix(matrix: number[][], target: number): boolean {
  // Define pointers for the top and bottom row of the matrix
  let top = 0;
  let bottom = matrix.length - 1;

  // First, perform binary search over the rows
  while (top <= bottom) {
    // Pick the middle row
    const row = Math.floor((top + bottom) / 2);

    // If target is greater than the last element in this row,
    // move search window down (to rows below)
    if (target > matrix[row][matrix[row].length - 1]) {
      top = row + 1;
    } 
    // If target is smaller than the first element in this row,
    // move search window up (to rows above)
    else if (target < matrix[row][0]) {
      bottom = row - 1;
    } 
    // Otherwise, the target must be within this row
    else {
      // Perform binary search within the row
      let l = 0;
      let r = matrix[row].length - 1;

      while (l <= r) {
        const mid = Math.floor((l + r) / 2);

        // If element matches target, return true
        if (matrix[row][mid] === target) return true;
        // If element is smaller, search right half
        else if (matrix[row][mid] < target) l = mid + 1;
        // If element is larger, search left half
        else r = mid - 1;
      }

      // If target not found in this row, return false
      return false;
    }
  }

  // If search exhausted all rows, return false
  return false;
}

// Example usage:
const matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
const target = 3;
console.log(searchMatrix(matrix, target)); // Output: true