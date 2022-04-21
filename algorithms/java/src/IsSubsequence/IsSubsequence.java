/***************************************************************************************************** 
 *
 * Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
 * 
 * A subsequence of a string is a new string that is formed from the original string by
 * deleting some (can be none) of the characters without disturbing the relative positions of
 * the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
 * 
 * Example 1:
 * 
 * Input: s = "abc", t = "ahbgdc"
 * Output: true
 * 
 * Example 2:
 *
 * Input: s = "axc", t = "ahbgdc"
 * Output: false
 * 
 * Constraints:
 * 
 *  0 <= s.length <= 100
 *  0 <= t.length <= 10^4
 *  s and t consist only of lowercase English letters.
 * 
 * 
 * Explanation of the solution:
 * 
 * Firstly we analyze de string 's' char by char, the string 't' is required to contain 
 * the analized char in order to return true. If 't' does not contains the char, we return false.
 * 
 * Secondly, if 't' contains the char we delete all the letters in 't' until the position of the 
 * char we have just analized (including the char, that is why we have add the 1 at the t.substring( ))
 * and we can also delete from 's' the recently analized char.
 * 
 * Finally, after deleting all the unwanted letters in 't' and 's', if the length of 's' is bigger 
 * than the length of 't' it means that the string 's' have more chars left to analize than the amount of
 * chars 't' contains, as a result we return false.
 * 
 * This is an example of the code:
 ******************************************************************************************************/

class Solution {
    public boolean isSubsequence(String s, String t) {  //The explanation is above
        for(char i : s.toCharArray()){
            if(!t.contains(String.valueOf(i))){
                return false;
            }
            t = t.substring(t.indexOf(i)+1);
            s = s.substring(1);
            if(s.length() > t.length()){
                return false;
            }
        }
        return true;
    }
}
