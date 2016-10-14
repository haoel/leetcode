// Source : https://oj.leetcode.com/problems/reverse-words-in-a-string/
// Author : Hao Chen, Siwei Xu
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // for std::reverse
using namespace std;

void reverseWords(string &s) {
    vector<string> words;
    bool found = false;
    int start = -1;
    const char space = ' ';
    for (int i = 0; i < s.size(); ++i){
        if (found && s[i] == space){
            words.push_back(s.substr(start, i-start));
            found = false;
        }else if (!found && s[i] != space){
            start = i;
            found = true;
        }
    }
    if (found) words.push_back(s.substr(start));
    s.clear();
    if (!words.empty()){
        for (int i = words.size()-1; i > 0; --i){
            s += words[i];
            s.push_back(space);
        }
        s += words[0];
    }
    cout << "[" << s << "]" <<endl;
}

// inspired from <Programming Pearls> -- Handwaving
void reverseWords2(string &s) {
    if (s.length() == 0) return;

    string result = "";
    if (s[s.length()-1] == ' ') {
        int last = s.find_last_not_of(' ') + 1;
        s.erase(last, s.length() - last);
    }

    int first = s.find_first_not_of(' ', 0);
    while (first != string::npos) {
        int wend = s.find(' ', first);  // word end
        if (wend == string::npos) wend = s.length();

        string word = s.substr(first, wend - first);
        reverse(word.begin(), word.end());
        result += word;

        first = s.find_first_not_of(' ', wend); // next word
        if (first == string::npos) break;

        result += ' ';
    }
    reverse(result.begin(), result.end());
    s.swap(result);
}


// C solution in O(1) space
void reverse(char *b, char *e) {
    for (--e; e - b > 0; b++, e--) {
        char t = *b;
        *b = *e;
        *e = t;
    }
}

void reverseWords(char *s) {
    char *p = s, *ws = NULL, *last = s;

    while (*p && *p == ' ') p++; // skip leading space
    ws = p;

    for ( ; *p; p++) {
        while (*p && *p != ' ') p++; // find word end

        reverse(ws, p);
        strncpy(last, ws, p-ws);
        last += (p-ws);

        while (*p && *p == ' ') p++; // for next word
        ws = p;

        if (*p == '\0') break;
        *last++ = ' ';
    }
    reverse(s, last);
    *last = '\0';
}

void test() {
#define TEST(str) do {       \
    char* s = strdup(str);   \
    printf("\"%s\" => ", s); \
    reverseWords(s);         \
    printf("\"%s\"\n\n", s); \
    free(s);                 \
    } while (0)

    TEST("  the    blue   sky  is blue    ");
    TEST("  ");
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

   test();
}    
