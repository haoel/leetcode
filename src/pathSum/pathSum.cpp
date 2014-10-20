// Source : https://oj.leetcode.com/problems/path-sum/
// Author : Hao Chen
// Date   : 2014-06-22

#include <time.h>

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
    Solution(){
        srand(time(NULL));
    }
    bool hasPathSum(TreeNode *root, int sum) {
        if (random()%2){
            return hasPathSum1(root, sum);    
        }
        return hasPathSum2(root, sum);
    }
    
    bool hasPathSum1(TreeNode *root, int sum) {
        if (root==NULL) return false;
        vector<TreeNode*> v;
        v.push_back(root);
        while(v.size()>0){
            TreeNode* node = v.back();
            v.pop_back();
            if (node->left==NULL && node->right==NULL){
                if (node->val == sum){
                    return true;
                }
            }
            if (node->left){
                node->left->val += node->val;
                v.push_back(node->left);
            }
            if (node->right){
                node->right->val += node->val;
                v.push_back(node->right);
            }
        }
        return false;
        
    }
    
    bool hasPathSum2(TreeNode *root, int sum) {
        
        if (root==NULL) return false;
        
        if (root->left==NULL && root->right==NULL ){
            return (root->val==sum);
        }
        
        if (root->left){
            root->left->val += root->val;
            if (hasPathSum2(root->left, sum)){
                return true;
            }
        }
        
        if (root->right){
            root->right->val += root->val;
            if (hasPathSum2(root->right, sum)){
                return true;
            }
        }
        
        return false;
    }

};
