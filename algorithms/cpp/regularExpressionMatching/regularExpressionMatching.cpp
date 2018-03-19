// Source : https://oj.leetcode.com/problems/regular-expression-matching/
// Author : Hao Chen
// Date   : 2014-08-24

/********************************************************************************** 
* 
* Implement regular expression matching with support for '.' and '*'.
* 
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
* 
* The matching should cover the entire input string (not partial).
* 
* The function prototype should be:
* bool isMatch(const char *s, const char *p)
* 
* Some examples:
* isMatch("aa","a") → false
* isMatch("aa","aa") → true
* isMatch("aaa","aa") → false
* isMatch("aa", "a*") → true
* isMatch("aa", ".*") → true
* isMatch("ab", ".*") → true
* isMatch("aab", "c*a*b") → true
* 
*               
**********************************************************************************/

#include <iostream>

bool MatchRegexp(const char* s, const char* p) {
  if (s == nullptr || p == nullptr) {
    return false;
  }

  while (*p != '\0') {
    if (*(p+1) == '*') {
      while ((*p != '.' && *s == *p) ||
	     (*p == '.' && *s != '\0')) {
	++s;
      }
      p += 2;
    } else {
      if ((*p != '.' && *s != *p) ||
	  (*s == '\0')) {
	return false;
      }
      ++p;
      ++s;
    } 
  }

  return *s == '\0';
}

int main() {
  std::cout << MatchRegexp("aa","a")<< "\n";
  std::cout << MatchRegexp("aa","aa")<< "\n";
  std::cout << MatchRegexp("aaa","aa")<< "\n";
  std::cout << MatchRegexp("aa", "a*")<< "\n";
  std::cout << MatchRegexp("aa", ".*")<< "\n";
  std::cout << MatchRegexp("ab", ".*")<< "\n";
  std::cout << MatchRegexp("aab", "c*a*b")<< "\n";
  return 0;
}
