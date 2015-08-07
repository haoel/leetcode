// Source : https://leetcode.com/problems/implement-trie-prefix-tree/
// Author : Hao Chen
// Date   : 2015-06-09

/********************************************************************************** 
 * 
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 * 
 *               
 **********************************************************************************/


class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode():isWord(false) {   }
    unordered_map<char, TrieNode*> children;
    bool isWord;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        if (s.size()<=0) return;
        TrieNode * node = root;
        for (int i=0; i<s.size(); i++) {
            if (node->children.find(s[i]) == node->children.end()){
                node->children[s[i]] = new TrieNode();
            }
            node = node->children[s[i]];
        }
        node->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        return retrieve(key, true);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return retrieve(prefix, false);
    }

private:

    inline bool retrieve(const string& key, bool isWord) {
        if (key.size() <= 0) return false;
        TrieNode * node = root;
        for (int i=0; i<key.length(); i++) {
            if (node->children.find(key[i]) == node->children.end()) {
                return false;
            }
            node = node->children[key[i]];
        }
        return isWord ? node->isWord : true;
    }

    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
