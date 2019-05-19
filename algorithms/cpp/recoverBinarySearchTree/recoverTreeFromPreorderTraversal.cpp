// source : https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
// Author Ahmed Morsy
// Date   : 2019-5-19

/********************************************************************************** 
*We run a preorder depth first search on the root of a binary tree.
*At each node in this traversal, we output D dashes (where D is the depth of this node), 
*then we output the value of this node.  
*(If the depth of a node is D, the depth of its immediate child is D+1.The depth of the root node is 0.)
*If a node has only one child, that child is guaranteed to be the left child.
*Given the output S of this traversal, recover the tree and return its root.

* Input: "1-2--3--4-5--6--7"
* Output: [1,2,5,3,4,6,7]

* Proposed Solution
  -----------------
 1. for each node in the input save its depth and value
 2. start a stack with the root node pushed onto it
    
    IF the following node has the root's depth + 1 and the root has less than 2 children then this node
    is a child for this root. Add it to the stack.
    
    ELSE then pop the current node from the stack.
    
**********************************************************************************/

/*  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
*/  


class Solution {
public:

    TreeNode* recoverFromPreorder(string S) {
        vector<int>values,depth;
        int cur_val = 0 , cur_depth = 0;
        bool dash = false;
        for(char s : S){
            if(s == '-'){
                if(!dash){
                    values.push_back(cur_val);
                    depth.push_back(cur_depth);
                    cur_depth = 0;
                    cur_val = 0;
                }
                dash = true;
                cur_depth++;
            }
            else{
                dash = false;
                cur_val *= 10;
                cur_val += s-'0';
            }
        }
        values.push_back(cur_val);
        depth.push_back(cur_depth);

        unordered_map<TreeNode*,int>depths;


        int ptr = 1;
        TreeNode *root = new TreeNode(values[0]);
        depths[root] = 0;
        stack<TreeNode*>st;
        st.push(root);

        while(ptr < (int)values.size()){
            TreeNode *cur = st.top();
            if(depth[ptr] == depths[cur]+1 && (cur->left == NULL || cur->right == NULL)){
                TreeNode *t = new TreeNode(values[ptr++]);
                depths[t] = depths[cur]+1;
                if(cur->left == NULL){
                    cur->left = t;
                }
                else{
                    cur->right = t;
                }
                st.push(t);
            }
            else{
                st.pop();
            }
        }
        return root;

    }
};

