// Source : https://oj.leetcode.com/problems/reverse-words-in-a-string/
// Author : Hao Chen
// Date   : 2014-06-16

/********************************************************************************** 
* 
* Given an input string, reverse the string word by word.
* 
* For example,
* Given s = "the sky is blue",
* return "blue is sky the".
* 
* 
* Clarification:
* 
* What constitutes a word?
* A sequence of non-space characters constitutes a word.
* Could the input string contain leading or trailing spaces?
* Yes. However, your reversed string should not contain leading or trailing spaces.
* How about multiple spaces between two words?
* Reduce them to a single space in the reversed string.
* 
*               
**********************************************************************************/

#include <ctype.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void reverseWords(string &s) {
    
    bool wordStart = false;
    vector<string> v;
    
    const char *pHead =s.c_str();
    const char *pStr, *pBegin, *pEnd;
   
    for (pStr=pHead; *pStr!='\0'; pStr++) {
        if (!isspace(*pStr) && wordStart == false){
            wordStart = true;
            pBegin = pStr;
            continue;
        }
        
        if(isspace(*pStr) && wordStart==true){
            wordStart=false;
            pEnd = pStr;
            v.insert(v.begin(), s.substr(pBegin-pHead, pEnd-pBegin) );
        }
        
    }

    if (wordStart==true){
        pEnd = pStr;
        v.insert(v.begin(), s.substr(pBegin-pHead, pEnd-pBegin) );
    }
    
    if (v.size()>0){
        s.clear();
        char space=' ';
        vector<string>::iterator it;
        for (it=v.begin(); it!=v.end(); ++it) {
            s = s + *it;
            s.push_back(space);
        }
        s.erase(s.end()-1);
    }else{
            s.clear();
    }
    cout << "[" << s << "]" <<endl;
}
    
main()
{
   string s;
   reverseWords(s);
   s=" ";
   reverseWords(s);
   s="1 ";
   reverseWords(s);
   s="love";
   reverseWords(s);
   s="i love cpp";
   reverseWords(s);

}    
