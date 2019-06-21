// Source : https://leetcode.com/problems/friend-circles/
// Author : Hao Chen
// Date   : 2019-03-26

/***************************************************************************************************** 
 *
 * 
 * There are N students in a class. Some of them are friends, while some are not. Their friendship is 
 * transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, 
 * then A is an indirect friend of C. And we defined a friend circle is a group of students who are 
 * direct or indirect friends.
 * 
 * Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] 
 * = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have 
 * to output the total number of friend circles among all the students.
 * 
 * Example 1:
 * 
 * Input: 
 * [[1,1,0],
 *  [1,1,0],
 *  [0,0,1]]
 * Output: 2
 * Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. The 2nd 
 * student himself is in a friend circle. So return 2.
 * 
 * Example 2:
 * 
 * Input: 
 * [[1,1,0],
 *  [1,1,1],
 *  [0,1,1]]
 * Output: 1
 * Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct 
 * friends, so the 0th and 2nd students are indirect friends. All of them are in the same friend 
 * circle, so return 1.
 * 
 * Note:
 * 
 * N is in range [1,200].
 * M[i][i] = 1 for all students.
 * If M[i][j] = 1, then M[j][i] = 1.
 * 
 ******************************************************************************************************/

class Solution {
public:

    // -----------------------------------------------------------------------------
    //DFS solution is quite easy to understand, just like the "Number of Island"
    int findCircleNum_DFS(vector<vector<int>>& M) {
        int n = 0;
        for (int i=0; i<M.size(); i++) {
            for (int j=0; j<M[0].size(); j++) {
                if ( M[i][j] == 1 ) {
                    n++;
                    M[i][j] = 2;
                    mark(M, j);
                }
            }
        }
        return n;
    }

    void mark(vector<vector<int>>& M, int i ) {
        for ( int j=0;  j<M[i].size(); j++ ){
            if ( M[i][j] == 1 ) {
                M[i][j] = 2;
                mark(M, j);
            }
        }
    }

    // -----------------------------------------------------------------------------
    //Union Find Solution
    int findCircleNum_UF(vector<vector<int>>& M) {

        vector<int> relations(M.size());
        for (int i=0; i<relations.size(); i++){
            relations[i] = i;
        }

        int n = M.size(); //by default, there are N friend cicles
        for (int i=0; i<M.size(); i++) {
            for (int j=0; j<M[0].size(); j++) {
                if ( M[i][j] == 1 && i != j ) {
                    if ( join(relations, i, j) ) n--;
                }
            }
        }
        return n;
    }

    //find the tail node.
    //   if a -> b -> c -> d, then find(a),find(b) or find(c) would return d;
    int find(vector<int>& relations, int i ) {
        while( relations[i] != i ) {
            i = relations[i];
        }
        return i;
    }
    // join the x cicle with y cicle,
    // if x and y are already in same friend cicle, then return false, else return true;
    bool join(vector<int> &relations, int x, int y) {
        int tx = find(relations, x);
        int ty = find(relations, y);
        if ( tx != ty ) relations[tx] = ty;
        return tx != ty;
    }

    // -----------------------------------------------------------------------------
    
    int findCircleNum(vector<vector<int>>& M) {
        return findCircleNum_UF(M);
        return findCircleNum_DFS(M);
    }
};
