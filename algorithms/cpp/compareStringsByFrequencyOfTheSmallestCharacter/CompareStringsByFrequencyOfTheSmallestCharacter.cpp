// Source : https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
// Author : Hao Chen
// Date   : 2019-10-01

/***************************************************************************************************** 
 *
 * Let's define a function f(s) over a non-empty string s, which calculates the frequency of the 
 * smallest character in s. For example, if s = "dcce" then f(s) = 2 because the smallest character is 
 * "c" and its frequency is 2.
 * 
 * Now, given string arrays queries and words, return an integer array answer, where each answer[i] is 
 * the number of words such that f(queries[i]) < f(W), where W is a word in words.
 * 
 * Example 1:
 * 
 * Input: queries = ["cbd"], words = ["zaaaz"]
 * Output: [1]
 * Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").
 * 
 * Example 2:
 * 
 * Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
 * Output: [1,2]
 * Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and 
 * f("aaaa") are both > f("cc").
 * 
 * Constraints:
 * 
 * 	1 <= queries.length <= 2000
 * 	1 <= words.length <= 2000
 * 	1 <= queries[i].length, words[i].length <= 10
 * 	queries[i][j], words[i][j] are English lowercase letters.
 ******************************************************************************************************/

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        cout << queries.size() << " : " << words.size() << endl;
        vector<int> freq;
        for (auto w : words) {
            freq.push_back(f(w));
        }
        sort(freq.begin(), freq.end());

        vector<int> result;
        for (auto q : queries) {
            result.push_back(binary_search(freq, f(q)));
        }
        return result;
    }

    int f(string& s) {
        char ch = 'z' + 1; //stroe the smallest char
        int cnt = 0;  //stroe the frequency of the smallest char
        for (auto c : s) {
            if (c < ch) { //find the smaller char, reset the count
                cnt  = 1;
                ch = c;
            } if (c == ch) {
                cnt++;
            }
        }
        return cnt;
    }

    int binary_search(vector<int> &v, int target) {
        int low=0, high=v.size()-1, mid;

        while (low < high) {
            mid = low + (high - low) / 2;
            if ( v[mid] > target) {
                high = mid -1;
            } else if (v[mid] <= target) {
                low = mid + 1;
            }
        }

        low = v[low] > target  ? low : low + 1;

        return v.size() - low;
    }

};
