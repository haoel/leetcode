// Source : https://leetcode.com/problems/word-search-ii/
// Author : Hao Chen
// Date   : 2015-06-10

/********************************************************************************** 
 * 
 * Given a 2D board and a list of words from the dictionary, find all words in the board.
 * 
 * Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" 
 * cells are those horizontally or vertically neighboring. The same letter cell may not be used 
 * more than once in a word.
 * 
 * For example,
 *   Given words = ["oath","pea","eat","rain"] and board = 
 *   
 *   [
 *     ['o','a','a','n'],
 *     ['e','t','a','e'],
 *     ['i','h','k','r'],
 *     ['i','f','l','v']
 *   ]
 *   
 * Return ["eat","oath"].
 * 
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 * 
 * click to show hint.
 * 
 * You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?
 * 
 * If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. 
 * What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? 
 * How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: 
 * Implement Trie (Prefix Tree) first.
 *               
 **********************************************************************************/

const int MAX_CHARS = 26;

class TrieNode {
    public:
        TrieNode(string s):isWord(false), word(s) {
            memset(children, 0, sizeof(children));
        }
        TrieNode* & operator [] (char ch) {
            return children[(ch - 'a') % MAX_CHARS];
        }
        TrieNode* & operator [] (int idx) {
            return children[idx % MAX_CHARS];
        }

    public:
        string word;
        bool isWord;
    private:
        TrieNode* children[MAX_CHARS];
};

class TrieTree {
    public:
        TrieTree():root(new TrieNode("")) { }
        ~TrieTree() { freeTree(root); }
        TrieNode* getRoot() {
            return root;
        }
        void addWord(string& s){
            TrieNode *node = root;
            string t;
            for (int i=0; i<s.size(); i++){
                t += s[i];
                if ( (*node)[s[i]] == NULL ){
                    (*node)[s[i]] = new TrieNode(t);
                }
                node = (*node)[s[i]];
            }
            node->isWord = true;
        }
    private:
        void freeTree(TrieNode* node){
            for(int i=0; i<MAX_CHARS; i++){
                if ((*node)[i]!=NULL){
                    freeTree((*node)[i]);
                }
            }
            delete node;
        }
        TrieNode *root;

};

class Solution {
public:
    void findWords(vector<vector<char>>& board, TrieNode* root, int row, int col, vector<string>& result){
        if (row < 0 || col < 0 || 
                row >= board.size() || 
                col >= board[row].size() ||
                board[row][col] == '\0' ) {
            return;
        }
        
        char ch = board[row][col];
        root = (*root)[ch];
        
        if (root==NULL) return;
        
        if (root->isWord){
            result.push_back(root->word);
            root->isWord = false;
        }
        
        
        board[row][col] = '\0';
        
        findWords(board, root, row, col - 1, result);
        findWords(board, root, row, col + 1, result);
        findWords(board, root, row + 1, col, result);
        findWords(board, root, row - 1, col, result);
        
        board[row][col] = ch;
        
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieTree t;
        for (int i = 0; i<words.size(); i++){
            t.addWord(words[i]);
        }
        
        vector<string> result;
        for (int i = 0; i<board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) { 
                findWords(board, t.getRoot(), i, j, result);
            }
        }
        return result;            
    }

};

