// Source : https://oj.leetcode.com/problems/validate-binary-search-tree/
// Author : Hao Chen
// Date   : 2014-07-05

#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode *root) {

    //travel the tree by inner-order
    vector<TreeNode*> stack;
    TreeNode* node = root;
    vector<int> v;
    while (stack.size()>0 || node!=NULL) {
        if (node!=NULL){
            stack.push_back(node);
            node = node->left;
        }else{
            node = stack.back();
            stack.pop_back();
            v.push_back(node->val);
            node = node->right;
        }
    }

    //check the vector wehther sorted or not
    for(int i=0; v.size()>0 && i<v.size()-1; i++){
        if (v[i] >= v[i+1]) {
            return false;
        }
    }

    return true;
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


int main()
{
    cout << isValidBST(NULL) << endl;

    int a[]={1,1};
    cout << isValidBST(createTree(a, sizeof(a)/sizeof(int))) << endl;
    
    int b[]={4,2,6,1,7,5,7};
    cout << isValidBST(createTree(b, sizeof(b)/sizeof(int))) << endl;

    int c[]={4,2,6,1,3,5,7};
    cout << isValidBST(createTree(c, sizeof(c)/sizeof(int))) << endl;
    return 0;
}
