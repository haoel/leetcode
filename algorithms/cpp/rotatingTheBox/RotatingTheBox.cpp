// Source : https://leetcode.com/problems/rotating-the-box/
// Author : Hao Chen
// Date   : 2021-05-22

/***************************************************************************************************** 
 *
 * You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the 
 * box is one of the following:
 * 
 * 	A stone '#'
 * 	A stationary obstacle '*'
 * 	Empty '.'
 * 
 * The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each 
 * stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity 
 * does not affect the obstacles' positions, and the inertia from the box's rotation does not affect 
 * the stones' horizontal positions.
 * 
 * It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the 
 * box.
 * 
 * Return an n x m matrix representing the box after the rotation described above.
 * 
 * Example 1:
 * 
 * Input: box = [["#",".","#"]]
 * Output: [["."],
 *          ["#"],
 *          ["#"]]
 * 
 * Example 2:
 * 
 * Input: box = [["#",".","*","."],
 *               ["#","#","*","."]]
 * Output: [["#","."],
 *          ["#","#"],
 *          ["*","*"],
 *          [".","."]]
 * 
 * Example 3:
 * 
 * Input: box = [["#","#","*",".","*","."],
 *               ["#","#","#","*",".","."],
 *               ["#","#","#",".","#","."]]
 * Output: [[".","#","#"],
 *          [".","#","#"],
 *          ["#","#","*"],
 *          ["#","*","."],
 *          ["#",".","*"],
 *          ["#",".","."]]
 * 
 * Constraints:
 * 
 * 	m == box.length
 * 	n == box[i].length
 * 	1 <= m, n <= 500
 * 	box[i][j] is either '#', '*', or '.'.
 ******************************************************************************************************/

class Solution {
public:
    void rotate(vector<vector<char>>& src, vector<vector<char>>& dest) {
        int m = src.size();
        for(int row=0; row<dest.size(); row++) {
            for(int col=0; col<dest[row].size(); col++) {
                dest[row][col] = src[m-col-1][row];
            }
        }
    }
    void gravity(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        for(int col=0; col<n; col++) {
            int bottom = m - 1;
            for(int row=m-1; row>=0; row-- ) {
                
                if (box[row][col] == '#') {
                    box[row][col] = '.';
                    box[bottom][col] = '#';
                    bottom--;
                }else if (box[row][col] == '*') {
                    bottom = row-1;
                }
            }
        }
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size();
        int col = box[0].size();
        vector<vector<char>> result(col, vector<char>(row,'.'));
        rotate(box, result);
        gravity(result);
        return result;
    }
};
