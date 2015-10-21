// Source : https://leetcode.com/problems/integer-to-english-words/
// Author : Hao Chen
// Date   : 2015-10-22

/*************************************************************************************** 
 *
 * Convert a non-negative integer to its english words representation. Given input is 
 * guaranteed to be less than 231 - 1.
 * 
 * For example,
 * 
 * 123 -> "One Hundred Twenty Three"
 * 12345 -> "Twelve Thousand Three Hundred Forty Five"
 * 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 * 
 *   Did you see a pattern in dividing the number into chunk of words? For example, 123 
 * and 123000.
 *
 *   Group the number by thousands (3 digits). You can write a helper function that 
 * takes a number less than 1000 and convert just that chunk to words.
 *
 *   There are many edge cases. What are some good test cases? Does your code work with 
 * input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)
 *               
 ***************************************************************************************/

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

static string dict1[] ={"Zero","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                 "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", 
                 "Seventeen", "Eighteen", "Nineteen"};
                 
static string dict2[]={"","", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
static string dict3[]={"Hundred", "Thousand", "Million", "Billion" };


// This function only converts the number which less than 1000
string numberLess1000ToWords(int num) {
    //char n[3] = {0, 0, 0};
    string result;

    if (num == 0) {
        return result;
    }else if (num < 20) {
        return dict1[num];
    } else if (num < 100) {
        result = dict2[num/10];
        if (num%10 > 0) { 
            result += " " + dict1[num%10];
        }
    }else {
        result = dict1[num/100] + " " + dict3[0];
        if ( num % 100 > 0 ) {
            result += " " + numberLess1000ToWords( num % 100 );
        }
    }
    return result;
}

string numberToWords(int num) {
    //edge case
    if (num ==0 ) return dict1[num];

    vector<string> ret;
    for( ;num > 0; num/=1000 ) {
        ret.push_back( numberLess1000ToWords(num % 1000) );
    }

    string result=ret[0];
    for (int i=1; i<ret.size(); i++){
        if (ret[i].size() > 0 ){
            if ( result.size() > 0 ) {
                result = ret[i] + " " + dict3[i] + " " + result; 
            } else {
                result = ret[i] + " " + dict3[i]; 
            }
        }

    }
    return result;
}


#define TEST(num) cout << num << " -> \"" << numberToWords(num) << "\"" << endl
int main(int argc, char** argv) 
{
    int num = 123;
    if (argc >1){
        num = atoi(argv[1]);
    }
    TEST(num);

    TEST(0);
    TEST(1);
    TEST(10);
    TEST(11);
    TEST(18);
    TEST(20);
    TEST(22);
    TEST(30);
    TEST(99);
    TEST(100);
    TEST(101);
    TEST(110);
    TEST(120);
    TEST(256);
    TEST(1000);
    TEST(1001);
    TEST(1010);
    TEST(1110);
    TEST(1111);
    TEST(10000);
    TEST(10001);
    TEST(100000);
    TEST(100001);
    TEST(1000000);
    TEST(1000001);
    TEST(10000000);
    TEST(10000001);
    TEST(100000000);
    TEST(100000001);
    TEST(1000000000);
    TEST(1000000001);
    TEST(2147483647);

    return 0;
}
