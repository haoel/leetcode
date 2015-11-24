// Source : https://oj.leetcode.com/problems/multiply-strings/
// Author : Hao Chen
// Date   : 2014-07-18

/********************************************************************************** 
* 
* Given two numbers represented as strings, return multiplication of the numbers as a string.
* 
* Note: The numbers can be arbitrarily large and are non-negative.
*               
**********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

string multiply(string& num, char ch){
    int n = ch - '0';
    string s;
    int carry = 0;
    int x;
    for(int i=num.size()-1; i>=0; i--){
        x = (num[i]-'0') * n + carry;
        carry = x/10;
        s.insert(s.begin(), x%10+'0'); 
    }
    if (carry>0) {
        s.insert(s.begin(), carry+'0');
    }
    return s;
}

string strPlus(string& num1, string& num2) {
    string s;
    int carry=0;
    int x;
    int n1 = num1.size(); 
    int n2 = num2.size(); 
    
    int i, j;
    for(i=n1-1, j=n2-1; i>=0 || j>=0; i--, j--){
        int x1 = i>=0 ?  num1[i]-'0' : 0;
        int x2 = j>=0 ?  num2[j]-'0' : 0;
        x = x1 + x2 + carry; 
        carry = x/10;
        s.insert(s.begin(), x%10+'0');
    }
    if (carry>0) {
        s.insert(s.begin(), carry+'0');
    }
    return s;
}

string multiply(string num1, string num2) {

    if (num1.size()<=0 || num2.size()<=0) return "";

    int shift=0;
    string result="0";
    for (int i=num1.size()-1; i>=0; i--) {
        string s = multiply(num2, num1[i]);        
        for(int j=0; j<shift; j++){
            s.insert(s.end(), '0');
        }
        result = strPlus(result, s);
        shift++;
    }
    //check if it is zero
    if (result[0]=='0') return "0";
    return result;
}


/********************************************************************************** 
 *                            Another implementation
 **********************************************************************************/

class Solution {
    public:

        string strPlus(string& num1, string& num2) {
            if (num1.size()==0) return num2;
            if (num2.size()==0) return num1;

            if ( num1.size() < num2.size() ) {
                swap(num1, num2);
            }

            string s;
            int carry=0;
            int x;
            for (int i=num1.size()-1, j=num2.size()-1; i>=0; i--, j--) {
                x = num1[i]-'0' + carry;
                if(j>=0){
                    x += num2[j]-'0';
                }
                s.insert(s.begin(), x%10+'0');
                carry = x/10;
            }
            if (carry>0) {
                s.insert(s.begin(), carry+'0');
            }

            return s;
        }


        string multiply(string num1, string num2) {

            if (num1.size()<=0 || num2.size()<=0) return "";

            string result;
            for ( int i=num1.size()-1; i>=0; i--) {
                int carry = 0;
                string val;
                for( int j=num2.size()-1; j>=0; j--) {
                    int v = (num2[j]-'0') * (num1[i]-'0') + carry;
                    val.insert(val.begin(), v%10+'0');
                    carry = v/10;
                }
                if (carry) val.insert(val.begin(), carry+'0');
                for (unsigned int j=i; j<num1.size()-1; j++) {
                    val.push_back('0');
                }
                result = strPlus(result, val);
            }

            //check if it is zero
            if (result[0]=='0') return "0";
            return result;

        }
};



int main(int argc, char**argv)
{
    string s1="20";
    string s2="25";
    if (argc>2){
        s1 = argv[1];
        s2 = argv[2];
    }
    cout << s1 << " * " << s2 << " = " << multiply(s1, s2) << endl;
    return 0;
}
