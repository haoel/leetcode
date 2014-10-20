// Source : https://oj.leetcode.com/problems/path-sum-ii/
// Author : Hao Chen
// Date   : 2014-07-01

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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> v;
        generatePathSum(root, sum, v, result);
        return result;
    }
    
    void generatePathSum(TreeNode *root, int sum, vector<int> v, vector<vector<int> >& result) {
        
        if (root==NULL) {
            return;
        }
        
        if (root->left==NULL && root->right==NULL) {
            if (root->val == sum){
                v.push_back(root->val);
                result.push_back(v);
            }
            return;
        }
        
        v.push_back(root->val);
        
        if (root->left) {
            generatePathSum(root->left, sum - root->val, v, result);
        }
        
        if (root->right) {
            generatePathSum(root->right, sum - root->val, v, result);
        }
    }
};
