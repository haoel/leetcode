// Source : https://leetcode.com/problems/cousins-in-binary-tree/
// Author : Hao Chen
// Date   : 2019-04-30

/***************************************************************************************************** 
 *
 * In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
 * 
 * Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
 * 
 * We are given the root of a binary tree with unique values, and the values x and y of two different 
 * nodes in the tree.
 * 
 * Return true if and only if the nodes corresponding to the values x and y are cousins.
 * 
 * Example 1:
 * 
 * Input: root = [1,2,3,4], x = 4, y = 3
 * Output: false
 * 
 * Example 2:
 * 
 * Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
 * Output: true
 * 
 * Example 3:
 * 
 * Input: root = [1,2,3,null,4], x = 2, y = 3
 * Output: false
 * 
 * Note:
 * 
 * 	The number of nodes in the tree will be between 2 and 100.
 * 	Each node has a unique integer value from 1 to 100.
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
    bool isCousins(TreeNode* root, int x, int y) {
        int dx=0, dy=0;
        TreeNode *px=root, *py=root;
        dx = DepthAndParent(root, px, 0, x);
        dy = DepthAndParent(root, py, 0, y);
        if (dx && dy){
            return (dx == dy && px != py);
        }

        return false;

    }

    int DepthAndParent(TreeNode* root, TreeNode*& parent, int depth, int x) {
        if (!root) return 0;
        if ( root->val == x) return depth;

        int d=0;
        parent = root;
        if  ( ( d = DepthAndParent(root->left, parent, depth+1, x)) > 0 ) return d;

        parent = root;
        if ( ( d = DepthAndParent(root->right, parent, depth+1, x)) > 0 ) return d;
        return 0;
    }
};
