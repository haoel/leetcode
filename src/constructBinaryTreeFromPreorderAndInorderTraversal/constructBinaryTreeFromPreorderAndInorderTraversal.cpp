// Source : https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Author : Hao Chen
// Date   : 2014-07-09

/********************************************************************************** 
* 
* Given preorder and inorder traversal of a tree, construct the binary tree.
* 
* Note:
* You may assume that duplicates do not exist in the tree.
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int>& preorder, int& preidx, vector<int>& inorder);

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int preidx=0;
    return buildTree(preorder, preidx, inorder);
}

TreeNode *buildTree(vector<int>& preorder, int& preidx, vector<int>& inorder) {

    if (preorder.size()<=0 || inorder.size()<=0 ) return NULL;

    TreeNode *root = new TreeNode(preorder[preidx]);
    if (inorder.size()==1){
        return root;
    }

    int i;
    for(i=0; i<inorder.size(); i++){
        if (inorder[i] == preorder[preidx]){
            break;
        }
    }

    //error: not found
    if (i == inorder.size()) return NULL;

    if (preidx+1 >= preorder.size()){
        return root;
    }

    
    vector<int> v(inorder.begin(), inorder.begin()+i);
    if (v.size()>0) {
        preidx++;
        root->left = buildTree(preorder, preidx, v);
    }

    v.clear();
    v.assign(inorder.begin()+i+1, inorder.end());
    if (v.size()>0) {
        preidx++;
        root->right = buildTree(preorder, preidx, v);
    }

    return root;
}

void printTree_pre_order(TreeNode *root)
{
    if (root == NULL){
        printf("# ");
        return;
    }
    printf("%c ", root->val );

    printTree_pre_order(root->left);
    printTree_pre_order(root->right);
}

void printTree_in_order(TreeNode *root)
{
    if (root == NULL){
        printf("# ");
        return;
    }

    printTree_in_order(root->left);
    printf("%c ", root->val );
    printTree_in_order(root->right);
}


void printTree_level_order(TreeNode *root)
{
    queue<TreeNode*> q;
    q.push(root);
    while (q.size()>0){
        TreeNode* n = q.front();
        q.pop();
        if (n==NULL){
            printf("# ");
            continue;
        }
        printf("%c ", n->val);
        q.push(n->left);
        q.push(n->right);
    }
    printf("\n");
}


int main()
{
    int pre_order[]={'F', 'B', 'A', 'D', 'C', 'E', 'G', 'I', 'H'};
    int  in_order[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    vector<int> preorder( pre_order, pre_order + 9 );
    vector<int>  inorder(  in_order,  in_order + 9 );

    TreeNode* tree = buildTree(preorder, inorder);

    printTree_level_order(tree);
    printTree_pre_order(tree);
    printf("\n");
    printTree_in_order(tree);
    printf("\n");
    
    return 0;
}
