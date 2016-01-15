// Source : https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// Author : Calinescu Valentin, Hao Chen
// Date   : 2015-12-08

/*************************************************************************************** 
 *
 * You are given an integer array nums and you have to return a new counts array. The 
 * counts array has the property where counts[i] is the number of smaller elements to 
 * the right of nums[i].
 * 
 * Example:
 * 
 * Given nums = [5, 2, 6, 1]
 * 
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 * 
 * Return the array [2, 1, 1, 0].
 * 
 ***************************************************************************************/


// The following idea is based on a `Binary Index Tree` or 'Fenwick Tree'
// There are two articles explaining this technique quite well:
// 1) http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
// 2) http://cs.stackexchange.com/questions/10538/bit-what-is-the-intuition-behind-a-binary-indexed-tree-and-how-was-it-thought-a

#define zeros(i) (i ^ (i - 1)) & i
class Solution {
public:
    vector <int> sorted, sol, fenwick;
    int n;
    int search(int t)
    {
        int step = 0;
        for(; (1 << step) <= n; step++);
        int i = 0;
        for(int k = step; k >= 0; k--)
            if(i + (1 << k) < n && sorted[i + (1 << k)] <= t)
                i += (1 << k);
        return i;
    }
    int compute(int t)
    {
        int s = 0;
        for(int i = t; i > 0; i -= zeros(i))
            s += fenwick[i];
        return s;
    }
    void add(int t)
    {
        for(int i = t; i <= n; i += zeros(i))
            fenwick[i]++;
    }
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size())
        {
            sorted = nums;
            n = nums.size();
            sort(sorted.begin(), sorted.end());
            vector <int> f(sorted.size());
            fenwick = f;
            for(int i = nums.size() - 1; i >= 0; i--)
            {
                int pos = search(nums[i]) + 1;
                sol.push_back(compute(pos - 1));
                add(pos);
            }
            reverse(sol.begin(), sol.end());
        }
        return sol;
    }
};


/*************************************************************************************** 
 * Another solution - Binary Search Tree
 ***************************************************************************************/


class BinarySearchTreeNode
{
    public:
        int val;     
        int less;      // count of members less than val
        int count;     // count of members equal val
        BinarySearchTreeNode *left, *right;
        BinarySearchTreeNode(int value) : val(value), less(0),count(1),left(NULL), right(NULL) {}
};

class BinarySearchTree
{
    private:
        BinarySearchTreeNode* root;
    public:
        BinarySearchTree(const int value):root(new BinarySearchTreeNode(value)){ }
        ~BinarySearchTree() {
            freeTree(root);
        }
        void insert(const int value, int &numLessThan) {
            insert(root, value, numLessThan);
        }
    private:
        void freeTree(BinarySearchTreeNode* root){
            if (root == NULL) return;
            if (root->left) freeTree(root->left);
            if (root->right) freeTree(root->right);
            delete root;
        }

        void insert(BinarySearchTreeNode* root, const int value, int &numLessThan) {

            if(value < root->val) {  // left
                root->less++;
                if(root->left == NULL) {
                    root->left = new BinarySearchTreeNode(value);
                }else{
                    this->insert(root->left, value, numLessThan);
                }
            } else if(value > root->val) { // right
                numLessThan += root->less + root->count;
                if(!root->right) {
                    root->right = new BinarySearchTreeNode(value);
                }else{
                    this->insert(root->right, value, numLessThan);
                }
            } else {
                numLessThan += root->less;
                root->count++;
                return;
            }
        }
};

class Solution {
    public:
        vector<int> countSmaller(vector<int>& nums) {
            vector<int> counts(nums.size());
            if(nums.size() == 0) return counts;

            BinarySearchTree tree(nums[nums.size()-1]);

            for(int i = nums.size() - 2; i >= 0; i--) {
                int numLessThan = 0;
                tree.insert( nums[i], numLessThan);
                counts[i] = numLessThan;
            }
            return counts; 
        }
};
