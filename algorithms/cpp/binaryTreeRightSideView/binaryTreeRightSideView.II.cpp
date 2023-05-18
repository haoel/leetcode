// Source : https://leetcode.com/problems/binary-tree-right-side-view/
// Author : David Lin
// Date   : 2023-05-18

/********************************************************************************** 
 * 
 * Given a binary tree, imagine yourself standing on the right side of it, return 
 * the values of the nodes you can see ordered from top to bottom.
 * 
 * For example:
 * Given the following binary tree,
 * 
 *      1            <---
 *    /   \
 *   2     3         <---
 *    \     \
 *     5     4       <---
 * 
 * You should return [1, 3, 4].
 * 
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


void printMatrix(vector<int>  &vv)
{   cout << "[";
    for(int i=0; i<vv.size(); i++) {
        

        cout << " " << vv[i];

        
    }
    cout << "]" << endl;
}


vector<int> rightSideView(TreeNode *root) {
    vector<int> Results;
    if(!root) return Results;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int length = q.size();
        int count{};
        while (count < length)
        {
            TreeNode* p = q.front();
            q.pop();
            if (count == length - 1) Results.push_back(p->val);
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
            count += 1;
            
        }
        
    }
    return Results;
}


void dfs(TreeNode* root, int level, vector<int>& Result){
    if (level == Result.size()) {
        Result.push_back(root->val);
    }
/*     printMatrix(Result); */
    if (root->right){
        dfs(root->right, level+1, Result);
    } 
    if (root->left){
        dfs(root->left, level+1, Result);
    } 
}


vector<int> rightSideView2(TreeNode *root){
    vector<int> Result;
    if(!root) return Result;
    int level;
    dfs(root, level, Result);
 /*    printMatrix(Result); */
    return Result;
    
}


int main()
{
    TreeNode *p;
    vector<int> vv;

    int a[] = {1,2,3,0,5,0,4};
    p = createTree(a, sizeof(a)/sizeof(int));
    printTree_level_order(p);
    vv = rightSideView(p);
    printMatrix(vv);
    cout << endl;

    int b[] = {1,2,3,0,5,0,4};
    p = createTree(b, sizeof(b)/sizeof(int));
    printTree_level_order(p);
    vv = rightSideView2(p);
    printMatrix(vv);
    cout << endl;
}