// Source : https://leetcode.com/problems/different-ways-to-add-parentheses/
// Author : Hao Chen
// Date   : 2015-08-15

/********************************************************************************** 
 * 
 * Given a string of numbers and operators, return all possible results from computing 
 * all the different possible ways to group numbers and operators. The valid operators 
 * are +, - and *.
 * 
 * Example 1
 * Input: "2-1-1". 
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 * Output: [0, 2]
 * 
 * Example 2
 * Input: "2*3-4*5" 
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 * Output: [-34, -14, -10, -10, 10] 
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test 
 * cases.
 *               
 **********************************************************************************/
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


bool isOperator(char ch){
    return (ch=='+' || ch=='-' || ch=='*');
}


//Divide & Conque  - recursive way
vector<int> diffWaysToCompute(string input) {
    //if the result has been cacluated, then just get it from the cache and return 
    static map< string, vector<int> > cache;
    if ( cache.find(input) != cache.end() ){
        return cache[input];
    }


    vector<int> result; 
    for (int i=0; i<input.size(); i++){
        char ch = input[i];
        if (isOperator(ch)){
            //split the input to two parts, left part and right part 
            //And recursively invoke this function.
            string left  = input.substr(0, i);
            string right = input.substr(i+1);
            vector<int> lv = diffWaysToCompute(left);
            vector<int> rv = diffWaysToCompute(right);

            //merge two result to one
            for(int li=0; li<lv.size(); li++) {
                for(int ri=0; ri<rv.size(); ri++) {
                    switch(ch){
                        case '+' : result.push_back(lv[li] + rv[ri]); break;
                        case '-' : result.push_back(lv[li] - rv[ri]); break;
                        case '*' : result.push_back(lv[li] * rv[ri]); break;
                    }
                }
            }

        }
    }
    //if we cannot find the "operator" in input, 
    //which means, it is a number, just put the number into the result. 
    if (result.size()==0) {
        result.push_back(atoi(input.c_str()));
    }
    
    //cache the result, key = input, value = result;
    cache[input] = result;

    return result;
}

void printVector(vector<int>& v) {
    cout << "[";
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << (i==v.size()-1 ? "]":", ");
    }
    cout << endl;
}

int main(int argc, char**argv) 
{
    string exp = "2*3-4*5";
    if ( argc > 1 ){
        exp = argv[1];
    }
    vector<int> v = diffWaysToCompute(exp);
    cout << exp << endl;
    printVector(v);
    return 0;
}

