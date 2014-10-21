// Source : https://oj.leetcode.com/problems/palindrome-partitioning/
// Author : Hao Chen
// Date   : 2014-08-21

/********************************************************************************** 
* 
* Given a string s, partition s such that every substring of the partition is a palindrome.
* 
* Return all possible palindrome partitioning of s.
* 
* For example, given s = "aab",
* 
* Return
* 
*   [
*     ["aa","b"],
*     ["a","a","b"]
*   ]
* 
*               
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool isPalindrome(string &s, int start, int end)  {  

    while(start < end)  
    {  
        if(s[start] != s[end]) { 
            return false;  
        }
        start++; end--;  
    }  
    return true;  
}  

void partitionHelper(string &s, int start, vector<string> &output, vector< vector<string> > &result) {

    if (start == s.size()) {
        result.push_back(output);
        return;
    }
    for(int i=start; i<s.size(); i++) {
        if ( isPalindrome(s, start, i) == true ) {
            output.push_back(s.substr(start, i-start+1) );
            partitionHelper(s, i+1, output, result);
            output.pop_back();
        }
    }
}

vector< vector<string> > partition(string s) {

    vector< vector<string> > result;
    vector<string> output;

    partitionHelper(s, 0,  output, result);

    return result;

}

void printMatrix(vector< vector<string> > &matrix)
{
    for(int i=0; i<matrix.size(); i++){
        cout << "{ ";
        for(int j=0; j< matrix[i].size(); j++) {
            cout << matrix[i][j] << ", ";
        }
        cout << "}" << endl;
    }
    cout << endl;
}


int main(int argc, char** argv)
{
    string s("aab");
    if ( argc > 1 ){
        s = argv[1];
    }

    vector< vector<string> > result = partition(s);

    printMatrix(result);
}
