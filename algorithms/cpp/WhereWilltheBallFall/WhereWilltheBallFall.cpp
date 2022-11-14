// https://leetcode.com/problems/where-will-the-ball-fall/

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        vector<int> res;
        
        for(int ball=0;ball<grid[0].size();ball++){
            int i = 0;
            int j = ball;
            while(i < N){
                int cell = grid[i][j];
				        // go left or right according to current cell (1 or -1)
                j += cell;
                // if got out of matrix
                if(j >= M || j < 0)
                    break;
                // if adjacent cell is closed (eg. going left and current is right)
                if(cell != grid[i][j])
                    break;
                // go down one cell
                i++;
            }
            // if got out safely. push column num ( j ) else push ( -1 )
            i == N ? res.push_back(j) : res.push_back(-1);
        }
        return res;
    }
};

