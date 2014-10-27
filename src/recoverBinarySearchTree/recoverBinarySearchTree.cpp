// Source : https://oj.leetcode.com/problems/recover-binary-search-tree/
// Author : Hao Chen
// Date   : 2014-10-11

/********************************************************************************** 
* 
* Two elements of a binary search tree (BST) are swapped by mistake.
* 
* Recover the tree without changing its structure.
* 
* Note:
* A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
* 
* confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
* 
* OJ's Binary Tree Serialization:
* 
* The serialization of a binary tree follows a level order traversal, where '#' signifies 
* a path terminator where no node exists below.
* 
* Here's an example:
* 
*    1
*   / \
*  2   3
*     /
*    4
*     \
*      5
* 
* The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}". 
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

//
// We can convert the BST to a sorted array,  then we can find the two nodes which missed the order.
//
// To cover the BST to sorted array, we needn't use an extra array, we just traverse the tree in order.
//  
//                   8
//           _______/ \_______
//          /                 \
//         4                  12
//      __/ \__             __/ \__
//     /       \           /       \
//    2         6        10        14
//   / \       / \       / \       / \
//  1   3     5   7     9  11    13  15
//  
//  
class Solution {
public:
    void recoverTreeHelper(TreeNode *root) {
        
        if (root == NULL) return;
        
        recoverTreeHelper(root->left);
        if (prev) {
            if (prev->val > root->val){
                if (n1==NULL) {
                    n1 = prev;
                }
                n2 = root;
            }
        }
        prev = root;
        recoverTreeHelper(root->right);
    }
    
    void recoverTree(TreeNode *root) {
        n1 = n2 = prev = NULL;
        recoverTreeHelper(root);
        if (n1 && n2) {
            swap(n1->val, n2->val);
        }
    }
private:
    TreeNode *n1, *n2, *prev;
};
