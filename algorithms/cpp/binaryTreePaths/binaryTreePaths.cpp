// Source : https://leetcode.com/problems/binary-tree-paths/
// Author : Calinescu Valentin, Hao Chen
// Date   : 2015-10-23

/*************************************************************************************** 
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * For example, given the following binary tree:
 * 
 *    1
 *  /   \
 * 2     3
 *  \
 *   5
 * 
 * All root-to-leaf paths are:
 * ["1->2->5", "1->3"]
 * 
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test 
 * cases.
 *               
 ***************************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> TreePaths;
    void DFS(TreeNode* node, string answer)
    {
        answer += "->" + to_string(node->val);
        if(node->left == NULL && node->right == NULL)
            TreePaths.push_back(answer);
        else
        {
            if(node->left != NULL)
                DFS(node->left, answer);
            if(node->right != NULL)
                DFS(node->right, answer);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root != NULL)
        {
            DFS(root, "");
            for(int i = 0; i < TreePaths.size(); i++)
                TreePaths[i].erase(TreePaths[i].begin(), TreePaths[i].begin() + 2);
        }
        return TreePaths;
    }
};




// Another more clear DFS implementation

class Solution {
public:
    void binaryTreePathsHelper(TreeNode* root, vector<int> solution, vector<string>& result ) {
        if (!root) return;
        
        solution.push_back(root->val);
        
        //meet the leaf node, shape a path into the result
        if (root->left==NULL && root->right==NULL){
            if(solution.size()>0){
                stringstream ss;
                for(int i=0; i<solution.size(); i++){
                    ss << solution[i] << (i<solution.size()-1 ? "->":"");
                }
                result.push_back(ss.str());
            }
            return;
        }
        
        binaryTreePathsHelper(root->left, solution, result);
        binaryTreePathsHelper(root->right, solution, result);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> solution;
        binaryTreePathsHelper(root, solution, result);
        return result;
    }
};
