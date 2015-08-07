// Source : https://oj.leetcode.com/problems/edit-distance/
// Author : Hao Chen
// Date   : 2014-08-22

/********************************************************************************** 
* 
* Given two words word1 and word2, find the minimum number of steps required to 
* convert word1 to word2. (each operation is counted as 1 step.)
* 
* You have the following 3 operations permitted on a word:
* 
* a) Insert a character
* b) Delete a character
* c) Replace a character
* 
*               
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


/*
 *  Dynamic Programming
 *
 *    Definitaion
 *
 *        m[i][j] is minimal distance from word1[0..i] to word2[0..j]
 *
 *    So, 
 *
 *        1) if word1[i] == word2[j], then m[i][j] == m[i-1][j-1].
 *
 *        2) if word1[i] != word2[j], then we need to find which one below is minimal:
 *
 *             min( m[i-1][j-1], m[i-1][j],  m[i][j-1] )
 *            
 *             and +1 - current char need be changed.
 *
 *        Let's take a look  m[1][2] :  "a" => "ab" 
 *
 *               +---+  +---+                                         
 *        ''=> a | 1 |  | 2 | '' => ab                                
 *               +---+  +---+                                         
 *                                                                    
 *               +---+  +---+                                         
 *        a => a | 0 |  | 1 | a => ab                                 
 *               +---+  +---+                                         
 *                                                            
 *        To know the minimal distance `a => ab`, we can get it from one of the following cases:
 *
 *            1) delete the last char in word1,  minDistance( '' => ab ) + 1                                                             
 *            2) delete the last char in word2,  minDistance(  a => a ) + 1                                                             
 *            3) change the last char,           minDistance( '' => a ) + 1                                                             
 *                                                            
 *  
 *    For Example:
 *
 *        word1="abb", word2="abccb"
 *
 *        1) Initialize the DP matrix as below:
 *
 *               "" a b c c b
 *            "" 0  1 2 3 4 5
 *            a  1
 *            b  2
 *            b  3
 *
 *        2) Dynamic Programming
 *
 *               "" a b c c b
 *            ""  0 1 2 3 4 5
 *            a   1 0 1 2 3 4 
 *            b   2 1 0 1 2 3
 *            b   3 2 1 1 1 2
 *
 */
int min(int x, int y, int z) {
    return std::min(x, std::min(y,z));
}

int minDistance(string word1, string word2) {
    int n1 = word1.size();     
    int n2 = word2.size();     
    if (n1==0) return n2;
    if (n2==0) return n1;
    vector< vector<int> > m(n1+1, vector<int>(n2+1));
    for(int i=0; i<m.size(); i++){
        m[i][0] = i;
    }
    for (int i=0; i<m[0].size(); i++) {
        m[0][i]=i;
    }

    //Dynamic Programming
    int row, col;
    for (row=1; row<m.size(); row++) {
        for(col=1; col<m[row].size(); col++){
            if (word1[row-1] == word2[col-1] ){
                m[row][col] = m[row-1][col-1];
            }else{
                int minValue = min(m[row-1][col-1], m[row-1][col],  m[row][col-1]);
                m[row][col] = minValue + 1;
            }
        }
    }

    return m[row-1][col-1];
}


int main(int argc, char**argv)
{
    string word1="abb", word2="abccb";
    if (argc>2){
        word1 = argv[1];
        word2 = argv[2];
    }

    int steps = minDistance(word1, word2);

    cout << word1 << ", " << word2 << " : " << steps << endl;
    return 0;
}
