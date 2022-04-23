// Source : https://leetcode.com/problems/longest-common-prefix/
// Author : Diego Ruiz Piqueras (Pikeras72)
// Date   : 22-04-2022

/***************************************************************************************************** 
 * Write a function to find the longest common prefix string amongst an array of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 * 
 * Example 2:
 *
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * Constraints:
 * 
 *  1 <= strs.length <= 200
 *  0 <= strs[i].length <= 200
 *  strs[i] consists of only lower-case English letters.
 * 
 * Explanation of the solution:
 * 
 * 1. Get the first word in the array 'strs'. As all the words in the array are believed to have 
 *    a common prefix, we compare if the other words have the same prefix (using containsPrefix(word, strs)).
 * 
 * 2. If a word in the array does not contain the same prefix we return false, otherwise (if all the words in 'strs' have the same prefix) we return true.
 *    If 'contains' is true we have found the prefix, in contrast, if 'contains' is false we continue looking
 *    for the prefix deleting the last character of the word given and using 'containsPrefix()' again.
 ******************************************************************************************************/

class Solution {
    public String longestCommonPrefix(String[] strs) {
        String word = strs[0];
        boolean contains;
        while(true){
            contains = containsPrefix(word,strs);
            if(!contains){
                word = word.substring(0,word.length()-1);   //Delete the last character
            }else{
                return word;
            }
        }
    }
  
    public boolean containsPrefix(String word, String[] strs){
        for(String i : strs){
            if(i.indexOf(word) != 0){     //The prefix must be at the beginning of the word
                return false;
            }
        }
        return true;
    }
}
