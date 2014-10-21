// Source : https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author : Hao Chen
// Date   : 2014-07-03

/********************************************************************************** 
* 
* Given a binary tree, flatten it to a linked list in-place.
* 
* For example,
* Given
* 
*          1
*         / \
*        2   5
*       / \   \
*      3   4   6
* 
* The flattened tree should look like:
* 
*    1
*     \
*      2
*       \
*        3
*         \
*          4
*           \
*            5
*             \
*              6
* 
* 
* Hints:
* If you notice carefully in the flattened tree, each node's right child points to 
* the next node of a pre-order traversal.
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
    void flatten(TreeNode *root) {
        
        vector<TreeNode*> v, stack;
        stack.push_back(root);
        while(stack.size()>0){
            TreeNode* node = stack.back();
            stack.pop_back();
            v.push_back(node);
            
            if (node && node->right){
                stack.push_back(node->right);
            }
            if (node && node->left){
                stack.push_back(node->left);
            }
        }
        
        v.push_back(NULL);
        for(int i=0; i<v.size(); i++){
            if (v[i]){
                v[i]->left = NULL;
                v[i]->right = v[i+1];
            }
        }
        
    }
};
