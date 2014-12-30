// Source : https://oj.leetcode.com/problems/balanced-binary-tree/
// Author : Hao Chen
// Date   : 2014-06-28

/********************************************************************************** 
* 
* Given a binary tree, determine if it is height-balanced.
* 
* For this problem, a height-balanced binary tree is defined as a binary tree in which 
* the depth of the two subtrees of every node never differ by more than 1.
* 
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
    bool isBalanced(TreeNode *root) {
        int height=0;
        return isBalancedUtil(root,&height);
    }
    bool isBalancedUtil(TreeNode* root,int *height){
       if(root==NULL){
          *height=0;
          return 1;
       }
       int lh=0,rh=0;
       bool isLeft,isRight;
       isLeft=isBalancedUtil(root->left,&lh);
       isRight=isBalancedUtil(root->right,&rh);
       *height=(lh>rh?lh:rh)+1;
       if(abs(lh-rh)>1)
          return 0;
       return isLeft&&isRight;
    }

};
