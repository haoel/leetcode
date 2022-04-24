// Source : https://leetcode.com/problems/valid-parentheses/
// Author : Diego Ruiz Piqueras (Pikeras72)
// Date   : 23-04-2022

/********************************************************************************************************* 
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']'
 * determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 1. Open brackets must be closed by the same type of brackets.
 * 
 * 2. Open brackets must be closed in the correct order.
 * 
 * Example 1:
 * 
 * Input: s = "()"
 * Output: true
 * 
 * Example 2:
 *
 * Input: s = "()[]{}"
 * Output: true
 * 
 * Explanation 3:
 * 
 * Input: s = "(]"
 * Output: false
 * 
 * Constraints:
 * 
 *  1 <= s.length <= 10^4
 *  s consists of parentheses only '()[]{}'.
 * 
 * Explanation of the solution:
 * 
 * 1. We analyze char by char the string 's' given, if we analyze an opening parentheses we can 
 *    include it in the Stack if the last parentheses added to the Stack was not another opening
 *    parentheses or if the Stack is empty.
 * 
 * 2. If we analyze a closing parentheses and the last introduced parentheses to the Stack is exactly the 
 *    opening parentheses of the one we are analyzing we eliminate the opening parentheses from the Stack.
 *    Else we return false.
 * 
 * 3. After having analyzed 's', if the Stack is empty it means all parentheses have being closed so we return
 *    true, if not, we return false;
 *************************************************************************************************************/

//I HAVE USED AN IF{}ELSE IF{} COMBINATION BUT YOU COULD HAVE USED A SWITCH{} TO CHECK THE TYPE OF PARENTHESES.
class Solution {
    public boolean isValid(String s) {
        Stack pila = new Stack();
        for (char i : s.toCharArray()){
            if(i == '('){
                pila.add(i);
            }else if(i == ')'){
                if (pila.isEmpty()){
                    return false;
                }else if (pila.peek().equals('(')){
                    pila.pop();
                }else {
                    return false;
                }
            }else if(i == '['){
                pila.add(i);
            }else if(i == ']'){
                if (pila.isEmpty()){
                    return false;
                }else if (pila.peek().equals('[')){
                    pila.pop();
                }else {
                    return false;
                }
            }else if(i == '{'){
                pila.add(i);
            }else{
                if (pila.isEmpty()){
                    return false;
                }else if (pila.peek().equals('{')){
                    pila.pop();
                }else {
                    return false;
                }
            }
        }
        if (pila.isEmpty()){
            return true;
        }
        return false;
    }
}
