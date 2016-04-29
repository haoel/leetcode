// Source : https://leetcode.com/problems/house-robber-iii/
// Author : Calinescu Valentin
// Date   : 2016-04-29

/*************************************************************************************** 
 *
 * The thief has found himself a new place for his thievery again. There is only one
 * entrance to this area, called the "root." Besides the root, each house has one and
 * only one parent house. After a tour, the smart thief realized that "all houses in
 * this place forms a binary tree". It will automatically contact the police if two 
 * directly-linked houses were broken into on the same night.
 * 
 * Determine the maximum amount of money the thief can rob tonight without alerting the
 * police.
 * 
 * Example 1:
 *     3
 *    / \
 *   2   3
 *    \   \ 
 *     3   1
 * Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * Example 2:
 *     3
 *    / \
 *   4   5
 *  / \   \ 
 * 1   3   1
 * Maximum amount of money the thief can rob = 4 + 5 = 9.
 * Credits:
 * Special thanks to @dietpepsi for adding this problem and creating all test cases.
 * 
 ***************************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  /* 
 * Solution 1 - O(N log N)
 * =========
 *
 * We can use a recursive function that computes the solution for every node of the tree 
 * using the previous solutions calculated for the left and right subtrees. At every step
 * we have 2 options:
 *
 * 1) Take the value of the current node + the solution of the left and right subtrees of
 * each of the left and right children of the current node.
 * 2) Take the solution of the left and right subtrees of the current node, skipping over
 * its value.
 *
 * This way we can make sure that we do not pick 2 adjacent nodes.
 *
 * If we implemented this right away we would get TLE. Thus, we need to optimize the
 * algorithm. One key observation would be that we only need to compute the solution for
 * a certain node once. We can use memoization to calculate every value once and then
 * retrieve it when we get subsequent calls. As the header of the recursive function
 * doesn't allow additional parameters we can use a map to link every node(a pointer) to
 * its solution(an int). For every call the map lookup of an element and its insertion
 * take logarithmic time and there are a constant number of calls for each node. Thus, the
 * algorithm takes O(N log N) time to finish.
 * 
 */
class Solution {
public:
    map<TreeNode*, int> dict;
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        else if(dict.find(root) == dict.end())
        {
            int lwith = rob(root->left);
            int rwith = rob(root->right);
            int lwithout = 0, rwithout = 0;
            if(root->left != NULL)
                lwithout = rob(root->left->left) + rob(root->left->right);
            if(root->right != NULL)
                rwithout = rob(root->right->left) + rob(root->right->right);
            //cout << lwith << " " << rwith << " " << lwithout << " " << rwithout << '\n';
            dict[root] = max(root->val + lwithout + rwithout, lwith + rwith);
        }
        return dict[root];
    }
};
