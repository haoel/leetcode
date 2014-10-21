// Source : https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
// Author : Hao Chen
// Date   : 2014-07-21

/********************************************************************************** 
* 
* Given a binary tree, return the preorder traversal of its nodes' values.
* 
* For example:
* Given binary tree {1,#,2,3},
* 
*    1
*     \
*      2
*     /
*    3
* 
* return [1,2,3].
* 
* Note: Recursive solution is trivial, could you do it iteratively?
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal1(TreeNode *root);
vector<int> preorderTraversal2(TreeNode *root);

vector<int> preorderTraversal(TreeNode *root) {
    if (random()%2){
        cout << "---method one---" << endl;
        return preorderTraversal1(root);
    }
    cout << "---method two---" << endl;
    return preorderTraversal2(root);
}

vector<int> preorderTraversal1(TreeNode *root) {
    vector<int> v;
    vector<TreeNode*> stack;
    if (root) {
        stack.push_back(root);
    }
    while (stack.size()>0){
        TreeNode* n = stack.back();
        v.push_back(n->val);
        stack.pop_back();
        if (n->right){
            stack.push_back(n->right);
        }
        if (n->left){
            stack.push_back(n->left);
        }
    }
    return v;
}

vector<int> preorderTraversal2(TreeNode *root) {
    vector<int> v;
    vector<TreeNode*> stack;
    stack.push_back((TreeNode*)NULL);
    TreeNode *top = root;
    while(top!=NULL){
        v.push_back(top->val);
        if (top->right !=NULL){
            stack.push_back(top->right);
        }

        if (top->left != NULL){
            stack.push_back(top->left);
        }

        top = stack.back();
        stack.pop_back();
    }
    return v;
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

void printTree_pre_order(TreeNode *root)
{
    if (root == NULL){
        //cout << "# ";
        return ;
    }
    cout << root->val << " ";
    printTree_pre_order(root->left);
    printTree_pre_order(root->right);
}


void printArray(vector<int> v)
{
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(0));
    int a[] = {1,2,3,4,5,0,6,0,0,7,8,9,0};
    TreeNode* p = createTree(a, sizeof(a)/sizeof(int));
    printTree_pre_order(p);
    cout << endl;
    vector<int> v = preorderTraversal(p);
    printArray(v);
    cout << endl;

    return 0;
}

