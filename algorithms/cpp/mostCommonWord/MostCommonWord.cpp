// Source : https://leetcode.com/problems/most-common-word/
// Author : Hao Chen
// Date   : 2018-04-19

/*************************************************************************************** 
 *
 * Given a paragraph and a list of banned words, return the most frequent word that is 
 * not in the list of banned words.  It is guaranteed there is at least one word that 
 * isn't banned, and that the answer is unique.
 * 
 * Words in the list of banned words are given in lowercase, and free of punctuation.  
 * Words in the paragraph are not case sensitive.  The answer is in lowercase.
 * 
 * 
 * Example:
 * Input: 
 * paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
 * banned = ["hit"]
 * Output: "ball"
 * Explanation: 
 * "hit" occurs 3 times, but it is a banned word.
 * "ball" occurs twice (and no other word does), so it is the most frequent non-banned 
 * word in the paragraph. 
 * Note that words in the paragraph are not case sensitive,
 * that punctuation is ignored (even if adjacent to words, such as "ball,"), 
 * and that "hit" isn't the answer even though it occurs more because it is banned.
 * 
 * 
 *  
 * 
 * Note: 
 * 
 * 
 * 	1 <= paragraph.length <= 1000.
 * 	1 <= banned.length <= 100.
 * 	1 <= banned[i].length <= 10.
 * 	The answer is unique, and written in lowercase (even if its occurrences in 
 * paragraph may have uppercase symbols, and even if it is a proper noun.)
 * 	paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
 * 	Different words in paragraph are always separated by a space.
 * 	There are no hyphens or hyphenated words.
 * 	Words only consist of letters, never apostrophes or other punctuation 
 * symbols.
 * 
 * 
 *  
 ***************************************************************************************/


class Solution {
private:
    bool isLetter(char c) {
        return c >= 'a' && c <= 'z';
    }
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> banned_map, words_map;
        for (auto w:banned) {
            banned_map[w]++;
        }
        
        //conert the string to lower case.
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        
        //transfer the symbols to space.
        for (int i=0; i<paragraph.size(); i++) {
            if ( !isLetter(paragraph[i]) ){
                paragraph[i] = ' ';
            }
        }
        string word;
        for(auto c:paragraph) {
            if (isLetter(c)) { 
                word += c;
            }else{
                if ( word.size()>0 ) {
                    words_map[word]++;
                }
                word="";
            }
        }
        if ( word.size()>0 ) words_map[word]++;
        
        string result;
        int max_cnt=0;
        // go through the words_map
        for (auto const& w : words_map) {
            
            if ( banned_map.find(w.first) != banned_map.end() ) {
                continue;
            }
            if (max_cnt < w.second) {
                result = w.first;
                max_cnt = w.second;
            }
        }

        return result;
    }
};
