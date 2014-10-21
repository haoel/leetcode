// Source : https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
// Author : Hao Chen
// Date   : 2014-10-10

/********************************************************************************** 
* 
* Given a binary tree, find the maximum path sum.
* 
* The path may start and end at any node in the tree.
* 
* For example:
* Given the below binary tree,
* 
*        1
*       / \
*      2   3
* 
* Return 6.
* 
*               
**********************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int maxPathSum(TreeNode *root, int& maxSum ) {

    if (NULL == root) return 0;

    int val = root->val;
    int left = root->left ? maxPathSum(root->left, maxSum) : 0;
    int right = root->right ? maxPathSum(root->right, maxSum) : 0;

    int maxBranch = left + val > right + val ?
        max(left + val, val) : max(right + val, val);

    int m = max(left + right + val, maxBranch);

    maxSum = max(maxSum, m);

    return maxBranch;
}

int maxPathSum(TreeNode *root) {
    #define INT_MIN     -2147483648
    int maxSum = INT_MIN;
    maxPathSum(root, maxSum);
    return maxSum;
}

int main()
{
    TreeNode root(1);
    TreeNode left(2);
    TreeNode right(3);
    root.left = &left;
    root.right = &right;
    cout << maxPathSum(&root) << endl; 
    return 0;
}
