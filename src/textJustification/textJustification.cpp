// Source : https://oj.leetcode.com/problems/text-justification/
// Author : Hao Chen
// Date   : 2014-10-11

/********************************************************************************** 
* 
* Given an array of words and a length L, format the text such that each line has 
* exactly L characters and is fully (left and right) justified.
*  
* 
* You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
* Pad extra spaces ' ' when necessary so that each line has exactly L characters.
* 
* Extra spaces between words should be distributed as evenly as possible. 
* If the number of spaces on a line do not divide evenly between words, 
* the empty slots on the left will be assigned more spaces than the slots on the right.
* 
* For the last line of text, it should be left justified and no extra space is inserted between words.
* 
* For example,
* words: ["This", "is", "an", "example", "of", "text", "justification."]
* L: 16.
* 
* Return the formatted lines as:
* 
* [
*    "This    is    an",
*    "example  of text",
*    "justification.  "
* ]
* 
* Note: Each word is guaranteed not to exceed L in length.
* 
* 
* Corner Cases:
* 
* A line other than the last line might contain only one word. What should you do in this case?
* In this case, that line should be left-justified.
* 
*               
**********************************************************************************/

#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> result;
    
    int len=0;
    int start = 0;
    int end = 0;
    double space =0;
    bool lastLine = false;
    for (int i=0; i<words.size(); i++){
        len += words[i].size();
        if (len + i - start > L || i == words.size()-1) {
            //remove the last one
            if (len + i - start > L) {  
                len -= words[i].size();
                end = i-1;
                lastLine = false;
            }else{
                end = i;
                lastLine = true;
            }
            //calculate the space number
            space = L - len;
            int mspace;
            int extra;
            if (lastLine){
                mspace = 1;
                extra = 0;
            } else {
                mspace = floor(space/(end-start));
                extra = space - mspace * (end-start);
            }

            string line = words[start];
            for (int j=start+1; j<=end; j++) {
                for(int k=0; k<mspace && space>0; k++, space--) {
                    line += " ";
                }   
                if (j-start-1 < extra){
                    line += " ";
                    space--;
                } 
                line += words[j];
            }
            //add the rest space
            if (space>0){
                for(; space>0; space--) {
                    line += " ";
                }
            }
            result.push_back(line);
            start = i;
            i = end;
            len = 0;
        } 
    }

    return result;
}


void printVector(vector<string> &words, bool newline=false) {
    for(int i=0; i<words.size(); i++) {
        cout << "\"" << words[i] << "\", ";
        if (newline) cout << endl; 
    }
    cout << endl;
}

void test(const char* A[], int len, int L) {
    vector<string> words(A, A+len);

    printVector(words);

    vector<string> result = fullJustify(words, L);
    cout << endl;
    printVector(result, true);

}

#define TEST(a, L) test(a, sizeof(a)/sizeof(const char*), L)

int main(int argc, char** argv)
{
    const char* w1[]={"This", "is", "an", "example", "of", "text", "justification."};
    TEST(w1, 16);    

    const char* w2[] = {"What","must","be","shall","be."}; 
    TEST(w2, 12);
    
    const char* w3[] = {"My","momma","always","said,","Life","was","like","a","box","of","chocolates.","You","never","know","what","you're","gonna","get."};
    TEST(w3, 20);

    return 0;
}
