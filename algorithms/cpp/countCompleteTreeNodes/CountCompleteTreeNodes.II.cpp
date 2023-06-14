// Source : https://leetcode.com/problems/count-complete-tree-nodes/
// Author : Sunny Lin
// Date   : 2023-05-18

/********************************************************************************** 
 * 
 * Given a complete binary tree, count the number of nodes.
 * 
 * Definition of a complete binary tree from Wikipedia:
 * http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees
 *
 * In a complete binary tree every level, except possibly the last, is completely filled, 
 * and all nodes in the last level are as far left as possible. 
 * It can have between 1 and 2^h nodes inclusive at the last level h.
 *               
 **********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>


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


class Solution {
public:
    //return -1 if it is not.
    int isCompleteTree(TreeNode* root) {
        if (!root) return 0;

        int cnt = 1;
        TreeNode *left = root, *right = root;
        for(; left && right; left=left->left, right=right->right) {
            cnt *= 2;
        }
      
        if (left!=NULL || right!=NULL) {
            return -1;
        }
        return cnt-1;
    }

    int countNodes(TreeNode* root) {
        int cnt = isCompleteTree(root);
        if (cnt != -1) return cnt;
        int leftCnt = countNodes(root->left);
        int rightCnt = countNodes(root->right);
        return leftCnt + rightCnt + 1;
    }
}; 


class Solution2 {
public:
    int GetHeight(TreeNode* root){
        int height = 0;
        while (root->left)
        {
            height++;
            root = root->left;
        }
        return height;
    }


    bool IsNodeExist(int idx_to_find, int height, TreeNode* root){
        int left = 0;
        int right = pow(2, height) - 1;
        while (left<right)
        {   
            int middle_idx = ceil(float(left+right)/2);
            if (idx_to_find >= middle_idx)
            {
                root = root->right;
                left = middle_idx;
            }else{
                root = root->left;
                right = middle_idx - 1;
            }
        }
        return root != NULL;

    }


    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int height = GetHeight(root);
        int uppercount = pow(2, height) - 1;
        int left = 0;
        int right = uppercount;
        while (left < right)
        {
            int idx_to_find = ceil(float(left+right)/2);
            if(IsNodeExist(idx_to_find, height, root)){
                left = idx_to_find;
            }else{
                right = idx_to_find-1;
            }
        }
        return uppercount + right + 1;
        
    }
}; 

int main()
{
    TreeNode *p;
    int vv;
    Solution s = Solution();


    int a[] = {1,2,3,0,5,0,4};
    p = createTree(a, sizeof(a)/sizeof(int));
    printTree_level_order(p);
    vv = s.countNodes(p);
    cout << vv <<endl;

    int b[] = {1,2};
    p = createTree(b, sizeof(b)/sizeof(int));
    printTree_level_order(p);
    vv = s.countNodes(p);
    cout << vv <<endl;
}