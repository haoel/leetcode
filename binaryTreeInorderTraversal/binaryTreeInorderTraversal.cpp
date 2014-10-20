// Source : https://oj.leetcode.com/problems/binary-tree-inorder-traversal/
// Author : Hao Chen
// Date   : 2014-06-27

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<TreeNode*> stack;
        vector<int> v;
        
        while(stack.size()>0 || root!=NULL){
            if (root!=NULL){
                stack.push_back(root);
                root = root->left;
            }else{
                if (stack.size()>0) {
                    root = stack.back();
                    stack.pop_back();
                    v.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return v;
    }
};
