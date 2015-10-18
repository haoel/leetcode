// Source : https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
// Author : Hao Chen
// Date   : 2014-07-17

/********************************************************************************** 
* 
* Given a binary tree, return the level order traversal of its nodes' values. 
* (ie, from left to right, level by level).
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
* return its level order traversal as:
* 
* [
*   [3],
*   [9,20],
*   [15,7]
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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder1(TreeNode *root);
vector<vector<int> > levelOrder2(TreeNode *root);
vector<vector<int> > levelOrder3(TreeNode *root);


vector<vector<int> > levelOrder(TreeNode *root) {
    if (random()%2){
        return levelOrder1(root);
    }
    if (random()%2){
        return levelOrder3(root);
    }
    return levelOrder2(root);
}

vector<vector<int> > levelOrder1(TreeNode *root) {
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

    return vv;
}

vector<vector<int> > levelOrder2(TreeNode *root) {
    vector< vector<int> > vv;
    vector<int> v;
    if (root){
        v.push_back(root->val);
        vv.push_back(v);
    }

    vector< vector<int> > vv_left, vv_right;
    if(root && root->left) {
        vv_left = levelOrder2(root->left);
    }
    if(root && root->right) {
        vv_right = levelOrder2(root->right);
    }

    //merge
    for(int i=0; i<vv_left.size() || i < vv_right.size(); i++){
        if (i<vv_left.size() && i<vv_right.size()){
            vv_left[i].insert(vv_left[i].end(), vv_right[i].begin(), vv_right[i].end());
            vv.push_back(vv_left[i]);
        }else if (i<vv_left.size()) {
            vv.push_back(vv_left[i]);
        }else {
            vv.push_back(vv_right[i]);
        }
    }

    return vv;
}

vector<vector<int> > levelOrder3(TreeNode *root) {
    vector< vector<int> > vv;
    if(root == NULL) return vv;

    int level = 0; // current level.
    TreeNode *last = root; // last node of currrent level.
    queue<TreeNode*> q;

    q.push(root);
    vv.push_back(vector<int>());
    while(!q.empty()) {
        TreeNode *p = q.front();
        q.pop();

        vv[level].push_back(p->val);
        if(p->left ) q.push(p->left);
        if(p->right) q.push(p->right);

        if(p == last) {
            level++;
            last = q.back();
            vv.push_back(vector<int>()); // new buffer for next row.
        }
    }
    vv.pop_back();

    return vv;
}

void printTree(TreeNode *root)
{
    if (root == NULL){
        printf("# ");
        return;
    }
    printf("%d ", root->val );

    printTree(root->left);
    printTree(root->right);
}

void printTree_level_order(TreeNode *root)
{
    queue<TreeNode*> q;
    q.push(root);
    while (q.size()>0){
        TreeNode* n = q.front();
        q.pop();
        if (n==NULL){
            cout << "# ";
            continue;
        }
        cout << n->val << " ";
        q.push(n->left);
        q.push(n->right);
    } 
    cout << endl;
}

TreeNode* createTree(int a[], int n)
{
    if (n<=0) return NULL;

    TreeNode **tree = new TreeNode*[n];

    for(int i=0; i<n; i++) {
        if (a[i]==0 ){
            tree[i] = NULL;
            continue;
        }
        tree[i] = new TreeNode(a[i]);
    } 
    int pos=1;
    for(int i=0; i<n && pos<n; i++) {    
        if (tree[i]){
            tree[i]->left = tree[pos++];
            if (pos<n){
                tree[i]->right = tree[pos++];
            }
        }
    }
    return tree[0];
}

int printMatrix(vector< vector<int> > &vv)
{
    for(int i=0; i<vv.size(); i++) {
        cout << "[";
        for(int j=0; j<vv[i].size(); j++) {
            cout << " " << vv[i][j];
        }
        cout << "]" << endl;;
    }
}

int main()
{
    TreeNode *p;
    vector< vector<int> > vv;

    int a[] = {1,2,3,4,5,0,0};
    p = createTree(a, sizeof(a)/sizeof(int));
    printTree_level_order(p);
    vv = levelOrder(p);
    printMatrix(vv);
    cout << endl;
    
    int b[] = {1,0,2};
    p = createTree(b, sizeof(b)/sizeof(int));
    printTree_level_order(p);
    vv = levelOrder(p);
    printMatrix(vv);
    cout << endl;

    int c[] = {1,2,0,3,0,4,0,5};
    p = createTree(c, sizeof(c)/sizeof(int));
    printTree_level_order(p);
    vv = levelOrder(p);
    printMatrix(vv);
    cout << endl;

    int d[] = {1,2,3,4,0,0,5};
    p = createTree(d, sizeof(d)/sizeof(int));
    printTree_level_order(p);
    vv = levelOrder(p);
    printMatrix(vv);
    cout << endl;
    return 0;
}
