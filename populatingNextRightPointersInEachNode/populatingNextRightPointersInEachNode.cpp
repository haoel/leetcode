// Source : https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Author : Hao Chen
// Date   : 2014-06-19

#include <stdio.h>
#include <vector>
using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
    TreeLinkNode() : val(0), left(NULL), right(NULL), next(NULL) {}
};


void connect(TreeLinkNode *root) {

    if (root==NULL){
        return;
    }
    if (root->left && root->right){
        root->left->next = root->right;
    }
    if (root->next && root->right){
        root->right->next = root->next->left;
    }
    connect(root->left);
    connect(root->right);

}

void connect1(TreeLinkNode *root) {

    if (root==NULL){
        return;
    }

    vector<TreeLinkNode*> v;    
    v.push_back(root);
    int i = 0;
    
    while (i < v.size()){
        if (v[i]->left){
            v.push_back(v[i]->left);
        }
        if (v[i]->right) {
            v.push_back(v[i]->right);
        }
        i++;
    }

    i=1;
    while(i<v.size()){
        for (int j=i-1; j<2*(i-1); j++){
           v[j]->next = v[j+1]; 
        }
        i *= 2; 
    }

}

void connect2(TreeLinkNode *root) {

    if (root==NULL){
        return;
    }
    
    vector<TreeLinkNode*> v;

    v.push_back(root);
    
    while(v.size()>0){
        
        if (root->left && root->right && root->left->next == NULL ) {
            root->left->next = root->right;
            
            if (root->next){
                root->right->next = root->next->left;
            }
            
            v.push_back(root->right);
            v.push_back(root->left);
        }
        root=v.back();
        v.pop_back();
    }
}

void printTree(TreeLinkNode *root){
    if (root == NULL){
        return;
    }
    printf("[%d], left[%d], right[%d], next[%d]\n", 
            root->val, 
            root->left ? root->left->val : -1, 
            root->right ? root->right->val : -1, 
            root->next?root->next->val : -1 );    

    printTree(root->left);
    printTree(root->right);
 
}

int main()
{
    const int cnt = 7; 
    TreeLinkNode a[cnt];
    for(int i=0; i<cnt; i++){
        a[i].val = i+1;
    } 

    
    for(int i=0, pos=0;  pos < cnt-1; i++ ){
        a[i].left = &a[++pos];
        a[i].right = &a[++pos];
    }
    
    connect(&a[0]); 

    printTree(&a[0]);

    return 0;
}
