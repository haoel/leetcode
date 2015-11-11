// Source : https://leetcode.com/problems/remove-invalid-parentheses/
// Author : Hao Chen
// Date   : 2015-11-11

/*************************************************************************************** 
 *
 * Remove the minimum number of invalid parentheses in order to make the input string 
 * valid. Return all possible results.
 * 
 * Note: The input string may contain letters other than the parentheses ( and ). 
 * 
 * Examples:
 * 
 * "()())()" -> ["()()()", "(())()"]
 * "(a)())()" -> ["(a)()()", "(a())()"]
 * ")(" -> [""]
 * 
 * Credits:Special thanks to @hpplayer for adding this problem and creating all test 
 * cases.
 *               
 ***************************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

//DFS 
void removeInvalidParenthesesHelper(string& s, int index, int pair,
                                    int remove_left, int remove_right, 
                                    string solution, unordered_set<string>& result) {

    char ch = s[index];

    //recusive ending 
    if ( ch == '\0' ) {
        if (pair==0 && remove_left==0 && remove_right==0 ) {
            result.insert(solution);
        }
        return;
    }
    //other char, move to next one
    if ( ch != '(' && ch != ')' ) {
        removeInvalidParenthesesHelper(s, index+1, pair, remove_left, remove_right, solution+ch, result);
        return;
    }
    
    //if we meet left one, and we need remove left one, 
    //then we have two choices : remove it, OR keep it.
    if ( ch == '(' ) {
        //revmoe it
        if (remove_left > 0 ) { 
            removeInvalidParenthesesHelper(s, index+1, pair, remove_left-1, remove_right, solution, result);
        }
        //keep it
        removeInvalidParenthesesHelper(s, index+1, pair+1, remove_left, remove_right, solution+ch, result);
    }
    
    //if we meet right one, and we need to remove right one,
    //then we have two choices as well: remove it, or keep it if there are some left already.
    if ( ch == ')' ) {
        if (remove_right > 0 ) {
            removeInvalidParenthesesHelper(s, index+1, pair, remove_left, remove_right-1, solution, result);
        }
        if (pair > 0){
            removeInvalidParenthesesHelper(s, index+1, pair-1, remove_left, remove_right, solution+ch, result);
        }
    }


}

vector<string> removeInvalidParentheses(string s) {

    //Calculating how many left/right parentheses need be removed!
    int remove_left = 0, remove_right = 0;
    for(auto c : s) {
        if ( c == '(' ) {
            remove_left++;
        }else if ( c == ')' ){
            if (remove_left > 0) {
                remove_left--; // if we matched
            }else{
                remove_right++;
            }
        }
    }

    unordered_set<string> result;
    removeInvalidParenthesesHelper(s, 0, 0, remove_left, remove_right, "", result);
    return vector<string>( result.begin(), result.end() );
}


void printVector(vector<string> result) {
    for( int i=0; i<result.size(); i++) {
        cout << i << ") " << result[i] << endl;
    }
}


int main(int argc, char** argv) {
    string s = "()())()";
    if (argc>1) {
        s = argv[1];
    }
    cout << s << endl;
    printVector( removeInvalidParentheses(s) );
    
    return 0;
}
