// Source : https://oj.leetcode.com/problems/binary-tree-postorder-traversal/
// Author : Hao Chen
// Date   : 2014-07-21

/********************************************************************************** 
* 
* Given a binary tree, return the postorder traversal of its nodes' values.
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
* return [3,2,1].
* 
* Note: Recursive solution is trivial, could you do it iteratively?
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal1(TreeNode *root);
vector<int> postorderTraversal2(TreeNode *root);


// We have two methods here.
//   1) the first one acutally is pre-order but reversed the access order.
//   2) the second one is the traditional one 

vector<int> postorderTraversal(TreeNode *root) {
    if (random()%2){
        cout << "---method one---" << endl;
        return postorderTraversal1(root);
    }
    cout << "---method two---" << endl;
    return postorderTraversal2(root);
}


vector<int> postorderTraversal1(TreeNode *root) {
    vector<int> v;
    vector<TreeNode*> stack;
    if (root) {
        stack.push_back(root);
    }
    while (stack.size()>0){
        TreeNode *n = stack.back();
        stack.pop_back();
        v.push_back(n->val);
        if (n->left){
            stack.push_back(n->left);
        } 
        if (n->right) {
            stack.push_back(n->right);
        }
    }
    std::reverse(v.begin(), v.end());  // the trick
    return v;
}

// traditional and standard way.
// using the stack to simulate the recursive function stack.
vector<int> postorderTraversal2(TreeNode *root) {
    vector<int> v;
    vector<TreeNode*> stack;
    TreeNode *node = root;
    TreeNode *lastVisitNode = NULL;
    while(stack.size()>0 || node!=NULL){

        if (node != NULL){
            // keep going the left
            stack.push_back(node);
            node = node->left;
        }else{
            TreeNode *n = stack.back();
            // left way is finsised, keep going to the right way
            if (n->right != NULL && lastVisitNode != n->right){
                node = n->right;
            }else{
                // both left and right has been accessed.
                stack.pop_back();
                v.push_back(n->val);
                lastVisitNode = n;
            }
        }
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

void printTree_post_order(TreeNode *root)
{
    if (root == NULL){
        //cout << "# ";
        return ;
    }
    printTree_post_order(root->left);
    printTree_post_order(root->right);
    cout << root->val << " ";
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
    printTree_post_order(p);
    cout << endl;
    vector<int> v = postorderTraversal(p);
    printArray(v);
    cout << endl;

    return 0;
}
