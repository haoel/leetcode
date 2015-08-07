// Source : https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Author : Hao Chen
// Date   : 2014-06-27

/********************************************************************************** 
* 
* Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
* (ie, from left to right, level by level from leaf to root).
* 
* For example:
* Given binary tree {3,9,20,#,#,15,7},
* 
*     3
*    / \
*   9  20
*     /  \
*    15   7
* 
* return its bottom-up level order traversal as:
* 
* [
*   [15,7],
*   [9,20],
*   [3]
* ]
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
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        queue<TreeNode*> q;
        vector< vector<int> > vv;
        vector<int> v;
        if (root){
            v.push_back(root->val);
            vv.push_back(v);
        }
        q.push(root);
        int i=0;
        vector<TreeNode*> vt;
        while(q.size()>0){
            TreeNode *p = q.front();
            q.pop();
            vt.push_back(p);
            if ( p==NULL ) {
                continue;
            }
            q.push(p->left);
            q.push(p->right);
        }
    
    
        int step = 2;
        int j;
        for (int i=1; i<vt.size(); i=j ){
            v.clear();
    
            int cnt=0;
            for (j=i; j<i+step && j<vt.size(); j++){
                if (vt[j]) {
                    v.push_back(vt[j]->val);
                    cnt += 2;
                }
            }
            step = cnt;
            if (v.size()>0) {
                vv.push_back(v);
            }
        }
        //reverse the order
        reverse(vv.begin(), vv.end());
        return vv;
    }
};
