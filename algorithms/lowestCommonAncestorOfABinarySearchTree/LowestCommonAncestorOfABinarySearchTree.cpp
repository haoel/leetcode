// Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Author : Hao Chen
// Date   : 2015-07-17

/********************************************************************************** 
 * 
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given 
 * nodes in the BST.
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is 
 * defined between two nodes v and w as the lowest node in T that has both v and w as 
 * descendants (where we allow a node to be a descendant of itself).”
 * 
 *         _______6______
 *        /              \
 *     ___2__          ___8__
 *    /      \        /      \
 *    0      _4       7       9
 *          /  \
 *          3   5
 * 
 * For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example 
 * is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according 
 * to the LCA definition.
 *               
 *               
 **********************************************************************************/


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        while(root) {
            if (p->val > root->val && q->val > root->val) {
                root = root->right;
                continue;
            }
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
                continue;
            }
            return root;
            
        }
        return NULL;
    }
};
