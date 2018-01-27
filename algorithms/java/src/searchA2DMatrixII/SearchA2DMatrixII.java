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
 * Notice:
 * 此题为杨氏矩阵典型例题，且与74题解法类似
 * 思路：
 * 永远选取右上角的数字rightTopNumber和target进行比较，直到找到或者指针越界。
 * 1、若相等，直接返回；
 * 2、若target比rightTopNumber大，则行指针下移
 * 3、若target比rightTopNumber小，则列指针左移
 **********************************************************************************/
package searchA2DMatrixII;

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
