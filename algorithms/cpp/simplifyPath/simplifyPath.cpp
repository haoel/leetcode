// Source : https://oj.leetcode.com/problems/simplify-path/
// Author : Hao Chen
// Date   : 2014-10-09

/********************************************************************************** 
* 
* Given an absolute path for a file (Unix-style), simplify it.
* 
* For example,
* path = "/home/", => "/home"
* path = "/a/./b/../../c/", => "/c"
* 
* 
* Corner Cases:
* 
* Did you consider the case where path = "/../"?
* In this case, you should return "/".
* Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
* In this case, you should ignore redundant slashes and return "/home/foo".
* 
*               
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}


string simplifyPath(string path) {

    string result;
    vector<string> elems = split(path, '/'); 
   
    int ignor = 0;
    for(int i=elems.size()-1; i>=0; i--) {
         
        if (elems[i]=="" || elems[i]=="." ){
            continue;
        }
        if (elems[i]==".."){
            ignor++;
            continue;
        }
        if (ignor>0){
            ignor--;
            continue;
        }
        if (result.size()==0){
            result = "/" + elems[i];
        }else{ 
            result = "/" + elems[i] + result;
        }
    }

    return  result.size() ? result : "/";
        
}

int main(int argc, char** argv)
{
    string path("/a/./b/../../c/");
    if (argc > 1 ){
        path = argv[1];
    }

    cout << path << " : " << simplifyPath(path) << endl;
}
