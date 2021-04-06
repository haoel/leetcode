// Source : https://leetcode.com/problems/sentence-similarity-iii/
// Author : Hao Chen
// Date   : 2021-04-06

/***************************************************************************************************** 
 *
 * A sentence is a list of words that are separated by a single space with no leading or trailing 
 * spaces. For example, "Hello World", "HELLO", "hello world hello world" are all sentences. Words 
 * consist of only uppercase and lowercase English letters.
 * 
 * Two sentences sentence1 and sentence2 are similar if it is possible to insert an arbitrary sentence 
 * (possibly empty) inside one of these sentences such that the two sentences become equal. For 
 * example, sentence1 = "Hello my name is Jane" and sentence2 = "Hello Jane" can be made equal by 
 * inserting "my name is" between "Hello" and "Jane" in sentence2.
 * 
 * Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. 
 * Otherwise, return false.
 * 
 * Example 1:
 * 
 * Input: sentence1 = "My name is Haley", sentence2 = "My Haley"
 * Output: true
 * Explanation: sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".
 * 
 * Example 2:
 * 
 * Input: sentence1 = "of", sentence2 = "A lot of words"
 * Output: false
 * Explanation: No single sentence can be inserted inside one of the sentences to make it equal to the 
 * other.
 * 
 * Example 3:
 * 
 * Input: sentence1 = "Eating right now", sentence2 = "Eating"
 * Output: true
 * Explanation: sentence2 can be turned to sentence1 by inserting "right now" at the end of the 
 * sentence.
 * 
 * Example 4:
 * 
 * Input: sentence1 = "Luky", sentence2 = "Lucccky"
 * Output: false
 * 
 * Constraints:
 * 
 * 	1 <= sentence1.length, sentence2.length <= 100
 * 	sentence1 and sentence2 consist of lowercase and uppercase English letters and spaces.
 * 	The words in sentence1 and sentence2 are separated by a single space.
 ******************************************************************************************************/

class Solution {
private:
    bool isWord(char ch) {
        return (ch >='a' && ch <= 'z' ) || ( ch >='A' && ch <= 'Z');
    }
    bool isSpace(char ch) {
        return (ch == ' ');
    }
    void split(string& s, vector<string>& words) {
        s += ' ';
        int start=0, end=0;
        while(start < s.size()) {
            while(isSpace(s[start])) start++;
            end = start;
            while(!isSpace(s[end])) end++;
            words.push_back(s.substr(start, end-start));
            start = end + 1;
        }
    }
    void print(vector<string>& v) {
        cout << "[";
        for(int i=0; i<v.size()-1; i++) {
            cout << v[i] << ", ";
        }
        cout << v[v.size()-1] << "]" << endl;
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        string& longstr = sentence1.size() >= sentence2.size() ? sentence1 : sentence2;
        string& shortstr = sentence1.size() < sentence2.size() ? sentence1 : sentence2;
        if ( longstr == shortstr ) return true;
        
        vector<string> words1, words2;
        split(shortstr, words1);
        split(longstr, words2);
        //print(words1); print(words2);
        
        int left=0, right=words1.size()-1;
        while(left< words1.size() && words1[left] == words2[left]) left++;
        
        int delta = words2.size() - words1.size();
        while(right>=left && words1[right] == words2[delta+right]) right--;
        //cout << left << ":" << right << ":" << delta << endl;
        
        return left > right;
    }
};
