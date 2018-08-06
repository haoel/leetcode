// Source : https://leetcode.com/problems/unique-morse-code-words/description/
// Author : Hao Chen
// Date   : 2018-06-29

/*************************************************************************************** 
 *
 * International orse Code defines a standard encoding where each letter is mapped to 
 * a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" 
 * maps to "-.-.", and so on.
 * 
 * For convenience, the full table for the 26 letters of the English alphabet is given 
 * below:
 * 
 * 
 * [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.",
 * "---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
 * 
 * Now, given a list of words, each word can be written as a concatenation of the orse 
 * code of each letter. For example, "cab" can be written as "-.-.-....-", (which is 
 * the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the 
 * transformation of a word.
 * 
 * Return the number of different transformations among all words we have.
 * 
 * 
 * Example:
 * Input: words = ["gin", "zen", "gig", "msg"]
 * Output: 2
 * Explanation: 
 * The transformation of each word is:
 * "gin" -> "--...-."
 * "zen" -> "--...-."
 * "gig" -> "--...--."
 * "msg" -> "--...--."
 * 
 * There are 2 different transformations, "--...-." and "--...--.".
 * 
 * 
 *  
 * 
 * Note:
 * 
 * 
 * 	The length of words will be at most 100.
 * 	Each words[i] will have length in range [1, 12].
 *     words[i] will only consist of lowercase letters.
 ***************************************************************************************/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        string MorseTable[26] = {".-","-...","-.-.","-..",".","..-.","--.",
                                 "....","..",".---","-.-",".-..","--","-.",
                                 "---",".--.","--.-",".-.","...","-","..-",
                                 "...-",".--","-..-","-.--","--.."};
        unordered_map<string, bool> transformations;
        for (auto word : words) {
            string morse;
            for (auto ch : word) {
                morse += MorseTable[ ch - 'a' ];
            }
            transformations[morse]=true;
        }
        return transformations.size();
    }
};
