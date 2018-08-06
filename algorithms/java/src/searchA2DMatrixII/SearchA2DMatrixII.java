// Source : https://leetcode.com/problems/search-a-2d-matrix-ii/description/
// Author : Tianming Cao
// Date   : 2018-01-27
/**********************************************************************************
 * Write an efficient algorithm that searches for a value in an m x n matrix. 
 * This matrix has the following properties:
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * For example,
 * 
 * Consider the following matrix:
 * 
 * [
 *   [1,   4,  7, 11, 15],
 *   [2,   5,  8, 12, 19],
 *   [3,   6,  9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 *
 **********************************************************************************/
package searchA2DMatrixII;
/**********************************************************************************
 * This probleam is similar to problem 74(https://leetcode.com/problems/search-a-2d-matrix/description/).
 * One solution is:
 * Compare rightTopNumber with target to judge rowIndex and colIndex which place to move,
 * until thay out of range or find target.
 * Another solution is using binarySearch.
 **********************************************************************************/
public class SearchA2DMatrixII {
	public boolean searchMatrix(int[][] matrix, int target) {
		if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
			return false;
		} else {
			int m=matrix.length;
			int n=matrix[0].length;
			int row=0;
			int col=n-1;
			while(row<m&&col>=0){
				int rightTopNumber=matrix[row][col];
				if(rightTopNumber==target){
					return true;
				}else if(target>rightTopNumber){
					row++;
				}else{
					col--;
				}
			}
			return false;
		}
	}

}
