// Source : https://oj.leetcode.com/problems/valid-number/
// Author : Hao Chen
// Date   : 2014-08-26

/********************************************************************************** 
* 
* Validate if a given string is numeric.
* 
* Some examples:
* "0" => true
* "   0.1  " => true
* "abc" => false
* "1 a" => false
* "2e10" => true
* 
* Note: It is intended for the problem statement to be ambiguous. 
*       You should gather all requirements up front before implementing one.
* 
*               
**********************************************************************************/

#include <iostream>
using namespace std;


bool isdigit(const char c){
    return (c>='0' && c<='9');
}
bool isspace(const char c) {
    return (c==' ' || c =='\t' || c=='\n' || c=='\r' || c=='\f' || c=='\v');
}

bool isNumber(const char *s) {
    bool point = false;
    bool hasE = false;
    
    //trim the space
    while(isspace(*s)) s++;
    //check empty 
    if (*s == '\0' ) return false;
    //check sign
    if (*s=='+' || *s=='-') s++;

    const char *head  = s;
    for(; *s!='\0'; s++){
        // if meet point
        if ( *s == '.' ){
            if ( hasE == true || point == true){
                return false;
            }
            if ( s == head && !isdigit(*(s+1))  ){
                return false;
            }
            point = true; 
            continue; 
        }
        //if meet "e"
        if ( *s == 'e' ){
            if ( hasE == true || s == head) {
                return false;
            }
            s++;
            if ( *s=='+' || *s=='-' )  s++;
            if ( !isdigit(*s) ) return false;
      
            hasE = true; 
            continue; 
        }
        //if meet space, check the rest chars are space or not
        if (isspace(*s)){
            for (; *s != '\0'; s++){
                if (!isspace(*s)) return false;
            }
            return true;
        }
        if ( !isdigit(*s) ) {
            return false;
        }
       
    }
    
    return true; 
}


#define TEST(s) cout << "\"" << s << "\"" << " : " << isNumber(s) << endl
int main(int argc, char** argv)
{
    const char* s="123";
    if(argc>1){
        s = argv[1];
    }
    TEST(s);

    TEST("1.044");
    TEST(" 1.044 ");
    TEST("1.a");
    TEST("abc");
    TEST("e");
    TEST("1e");
    TEST("1e2");
    TEST("");
    TEST(" ");
    TEST("1.");
    TEST(".2");
    TEST(" . ");
    TEST(".");
    TEST("1.2.3");
    TEST("1e2e3");
    TEST("1..");
    TEST("+1.");
    TEST(" -1.");
    TEST("6e6.5");
    TEST("005047e+6");
    

    return 0;
}
