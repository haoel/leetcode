// Source : https://oj.leetcode.com/problems/valid-parentheses/
// Author : Yasser Elsayed & Suhib Alsisan
// Date   : 2016-04-24

/********************************************************************************** 
* 
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
* determine if the input string is valid.
* 
* The brackets must close in the correct order, "()" and "()[]{}" are all valid 
* but "(]" and "([)]" are not.
* 
*               
**********************************************************************************/

class Solution(object):
    def isValid(self, s):
        s = re.sub(r'[^\{\(\[\]\)\}}]', '', s);
        braces = {'}': '{', ')': '(', ']': '['};
        myStack = [];
        for i in s:
            if i in braces:
                if not len(myStack) or braces[i] != myStack.pop():
                    return False;
            else:
                myStack.append(i);
        return not len(myStack);
