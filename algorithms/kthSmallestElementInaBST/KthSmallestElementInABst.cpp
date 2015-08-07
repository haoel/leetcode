// Source : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Author : Hao Chen
// Date   : 2015-07-03

/********************************************************************************** 
 * 
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 * 
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? 
 * How would you optimize the kthSmallest routine?
 * 
 *   Try to utilize the property of a BST.
 *   What if you could modify the BST node's structure?
 *   The optimal runtime complexity is O(height of BST).
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
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
    // in-order travel - recursive way
    int kthSmallestHelper_recursive(TreeNode* root, int& k) {
        if (root==NULL) return 0; //this behavior is undefined!
        
        //in-order travel
        int result = kthSmallestHelper_recursive(root->left, k);
        if (k==0) return result;
        
        k--;
        if (k==0) return root->val;
        
        
        return kthSmallestHelper_recursive(root->right, k);
    }
    // in-order travel - non-recursive way
    int kthSmallestHelper_nonRecursive(TreeNode* root, int k){
        stack<TreeNode*> s;
        
        while(!s.empty() || root){
            
            while (root) { 
                s.push(root);
                root = root->left;
            }
            
            k--;
            root = s.top()->right;

            if (k==0) return s.top()->val;
            
            s.pop();
        }
        return -1;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        //return kthSmallestHelper_nonRecursive(root, k);
        return kthSmallestHelper_recursive(root, k);
    }
};
