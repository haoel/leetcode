// Source : https://leetcode.com/problems/binary-tree-right-side-view/
// Author : Hao Chen
// Date   : 2015-04-07

/********************************************************************************** 
 * 
 * Given a binary tree, imagine yourself standing on the right side of it, return 
 * the values of the nodes you can see ordered from top to bottom.
 * 
 * For example:
 * Given the following binary tree,
 * 
 *      1            <---
 *    /   \
 *   2     3         <---
 *    \     \
 *     5     4       <---
 * 
 * You should return [1, 3, 4].
 * 
 * Credits:Special thanks to @amrsaqr for adding this problem and creating all test cases.
 *               
 **********************************************************************************/

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
    void rightSideViewHelper(TreeNode* root, int level, vector<int>& result) {
        if (root == NULL) return;
        if ( result.size() < level ) result.push_back(root->val);
        rightSideViewHelper(root->right, level+1, result);
        rightSideViewHelper(root->left, level+1, result);
    }
    
    void rightSideViewHelper(TreeNode* root, vector<int>& result) {
        if (root==NULL) return;

        vector<TreeNode*> stack;
        vector<int> level;
        stack.push_back(root);
        level.push_back(1);
        
        while (stack.size()>0) {
            TreeNode* r = stack.back(); stack.pop_back();
            int l = level.back(); level.pop_back();
            if ( result.size() < l ) {
                result.push_back(r->val);
            }
            if (r->left) {
                stack.push_back(r->left);
                level.push_back(l+1);
            }
            if (r->right) {
                stack.push_back(r->right);
                level.push_back(l+1);
            }
        }
    }
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        if (rand()%2){
            rightSideViewHelper(root, 1, result);
        }else{
            rightSideViewHelper(root, result);
        }
        return result;
    }
};
