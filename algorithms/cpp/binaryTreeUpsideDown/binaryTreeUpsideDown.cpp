// Source : https://oj.leetcode.com/problems/binary-tree-upside-down/
// Author : Hao Chen
// Date   : 2014-11-17

/********************************************************************************** 
* Given a binary tree where all the right nodes are either leaf nodes with 
* a sibling (a left node that shares the same parent node) or empty, 
* 
* Flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. 
* Return the new root.
* 
* For example:
* Given a binary tree {1,2,3,4,5},
*     1
*    / \
*   2   3
*  / \
* 4   5
* return the root of the binary tree [4,5,2,#,#,3,1].
*    4
*   / \
*  5   2
*     / \
*    3   1  
* confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ. 
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
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        //using a dummy node to help to store the new tree      
        TreeNode dummy(0);
        TreeNode *head =  &dummy, *left=NULL, *right=NULL;

        while ( root!=NULL ) {
            //find the right & left
            left = root->right;
            right = root;
            
            //move root the next
            root = root->left;
            
            //replace the right with current root
            right->left = head->left;
            right->right = head->right;
            
            //move the dummy to the root
            dummy.right = right;
            dummy.left = left;
            
            //reset the head to the root
            head = &dummy;
    
        }
        
        return head->right;
    }
};
