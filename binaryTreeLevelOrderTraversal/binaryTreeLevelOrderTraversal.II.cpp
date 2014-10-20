// Source : https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Author : Hao Chen
// Date   : 2014-06-27

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
