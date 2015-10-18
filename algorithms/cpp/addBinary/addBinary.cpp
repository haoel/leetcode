// Source : https://oj.leetcode.com/problems/add-binary/
// Author : Hao Chen
// Date   : 2014-07-05

/********************************************************************************** 
* 
* Given two binary strings, return their sum (also a binary string).
* 
* For example,
* a = "11"
* b = "1"
* Return "100".
* 
*               
**********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b) {
    int alen = a.size();
    int blen = b.size();
    bool carry = false;
    string result;
    while( alen>0 || blen>0) {
        int abit = alen<=0 ? 0 : a[alen-1]-'0';
        int bbit = blen<=0 ? 0 : b[blen-1]-'0';
        int cbit = carry ? 1 : 0;
        result.insert(result.begin(), '0' + ((abit+bbit+cbit) & 1) );
        carry = (abit+bbit+cbit>1);
        alen--; blen--;
    }
    if (carry){
        result.insert(result.begin(), '1');
    }
    return result;
}


int main(int argc, char** argv) 
{
    string a = "11";
    string b = "1";
    if (argc>2){
        a = argv[1];
        b = argv[2];
    }

    cout << a << "+" << b << "=" << addBinary(a, b) << endl;
    
}
