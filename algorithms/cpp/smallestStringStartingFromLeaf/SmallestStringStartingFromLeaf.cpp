// Source : https://leetcode.com/problems/smallest-string-starting-from-leaf/
// Author : Hao Chen
// Date   : 2019-02-05

/***************************************************************************************************** 
 *
 * Given the root of a binary tree, each node has a value from 0 to 25 representing the letters 'a' to 
 * 'z': a value of 0 represents 'a', a value of 1 represents 'b', and so on.
 * 
 * Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.
 * 
 * (As a reminder, any shorter prefix of a string is lexicographically smaller: for example, "ab" is 
 * lexicographically smaller than "aba".  A leaf of a node is a node that has no children.)
 * 
 * Example 1:
 * 
 * Input: [0,1,2,3,4,3,4]
 * Output: "dba"
 * 
 * Example 2:
 * 
 * Input: [25,1,3,1,3,0,2]
 * Output: "adz"
 * 
 * Example 3:
 * 
 * Input: [2,2,1,null,1,0,null,0]
 * Output: "abc"
 * 
 * Note:
 * 
 * 	The number of nodes in the given tree will be between 1 and 1000.
 * 	Each node in the tree will have a value between 0 and 25.
 * 
 ******************************************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string str, result="{"; //'z'+1;
        smallestFromLeafHelper(root, str, result);
        return result;
    }
    
    void smallestFromLeafHelper(TreeNode* root, string str, string& result) {
        if (root->left == NULL && root->right == NULL) {
            str.insert(0, 1, char(root->val+'a'));
            result = min(result, str);
            return;
        }
        
        str.insert(0, 1, char(root->val+'a'));
        
        if (root->left) {
            smallestFromLeafHelper(root->left, str, result);
        }
        if (root->right) {
            smallestFromLeafHelper(root->right, str, result);
        }
    }
};
