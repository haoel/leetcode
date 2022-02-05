/*

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000

*/


//when looking for a pattern, we notice that there numbers in groups of four that change positions with one another
//approach: find the positions of those four and swamp them with their right neighbor to make the 90 degree turn

class Solution {
    public void rotate(int[][] matrix) {
        
        int n = matrix.length; //given
        
        //adding one and dividing with int division accounts for both odd and even length of n
        for (int i = 0; i < ((n + 1) / 2); i ++) {
            
            for (int j = 0; j < (n / 2); j++) {
                
                //Starts with far edges and works its way back to the left
                //hold first of group, use to replace in final swap
                int temp = matrix[n - j - 1][i]; 
                
                //keep replacing with group member on next side of the square
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1]; 
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = matrix[i][j];
                
                //finally replace last spot with first spot held in temp
                matrix[i][j] = temp;
                
                //move to next group with index incrementation
            }
        }
    }
}
