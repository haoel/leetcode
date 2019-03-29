// Source : https://leetcode.com/problems/distribute-coins-in-binary-tree/
// Author : Hao Chen
// Date   : 2019-03-29

/***************************************************************************************************** 
 *
 * Given the root of a binary tree with N nodes, each node in the tree has node.val coins, and there 
 * are N coins total.
 * 
 * In one move, we may choose two adjacent nodes and move one coin from one node to another.  (The 
 * move may be from parent to child, or from child to parent.)
 * 
 * Return the number of moves required to make every node have exactly one coin.
 * 
 * Example 1:
 * 
 * Input: [3,0,0]
 * Output: 2
 * Explanation: From the root of the tree, we move one coin to its left child, and one coin to its 
 * right child.
 * 
 * Example 2:
 * 
 * Input: [0,3,0]
 * Output: 3
 * Explanation: From the left child of the root, we move two coins to the root [taking two moves].  
 * Then, we move one coin from the root of the tree to the right child.
 * 
 * Example 3:
 * 
 * Input: [1,0,2]
 * Output: 2
 * 
 * Example 4:
 * 
 * Input: [1,0,0,null,3]
 * Output: 4
 * 
 * Note:
 * 
 * 	1<= N <= 100
 * 	0 <= node.val <= N
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
    int distributeCoins(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }

    //
    // if a node has 0 coin, which means one move from its parent.
    //               1 coin, which means zero move from its parent.
    //               N coins, which means N-1 moves to its parent.
    //
    // So, we can simply know, the movement = coins -1.
    // - negative number means the the coins needs be moved in.
    // - positive number means the the coins nees be moved out.
    //
    // A node needs to consider the movement requests from both its left side and right side.
    // and need to calculate the coins after left and right movement.
    //
    // So, the node coins  = my conins - the coins move out + the coins move in.
    //
    // Then we can have to code as below.
    //
    int dfs(TreeNode* root, int& result) {
        if (root == NULL) return 0;

        int left_move = dfs(root->left, result);
        int right_move = dfs(root->right, result);
        result += (abs(left_move) + abs(right_move));

        // the coin after movement: coins = root->val +left_move + right_move
        // the movement needs:  movement = coins - 1
        return root->val + left_move + right_move - 1;
    }
};
