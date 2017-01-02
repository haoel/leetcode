// Source : https://leetcode.com/problems/maximum-product-of-word-lengths/
// Author : Hao Chen
// Date   : 2017-01-02

/*************************************************************************************** 
 *
 * Given a string array words, find the maximum value of length(word[i]) * 
 * length(word[j]) where the two words do not share common letters.
 *     You may assume that each word will contain only lower case letters.
 *     If no such two words exist, return 0.
 * 
 *     Example 1:
 * 
 *     Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
 *     Return 16
 *     The two words can be "abcw", "xtfn".
 * 
 *     Example 2:
 * 
 *     Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
 *     Return 4
 *     The two words can be "ab", "cd".
 * 
 *     Example 3:
 * 
 *     Given ["a", "aa", "aaa", "aaaa"]
 *     Return 0
 *     No such pair of words.    
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test 
 * cases.
 ***************************************************************************************/

class Solution {
public:
    //
    // there are two algorithms:
    //
    // 1) compare two words is same or not 
    //    - we can use bit-mask to solve that. 
    //    - we need be careful about one word is subset of another one, such as: "abc" is subset of "abcabc"
    //
    // 2) find out the max product - that needs O(N^2) time complexity algorithm.
    //

    int maxProduct(vector<string>& words) {
        //Key is the word's bitmask, and the value the max length of that bit mask
        unordered_map<int, int> maxLens;
        //constructing the bitmask.
        for(auto& w: words) {
            int mask = 0;
            for (auto& c: w) {
                mask = mask | ( 1 << (c-'a') );
            }
            if ( maxLens.find(mask) == maxLens.end() || maxLens[mask] < w.size() ) {
                maxLens[mask] = w.size();
            }
        }
        
        //find out the max product
        int result = 0;
        for (auto a : maxLens) {
            for (auto b: maxLens) {
                // if `a` and `b` is same, then just simply continue
                if (a.first & b.first) continue; // there are common letters
                result = max( result, a.second * b.second );
            }
        }
        
        return result;
    }
};
