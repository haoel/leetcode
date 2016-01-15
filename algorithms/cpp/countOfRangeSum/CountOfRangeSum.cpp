// Source : https://leetcode.com/problems/count-of-range-sum/
// Author : Hao Chen
// Date   : 2016-01-15

/*************************************************************************************** 
 *
 * Given an integer array nums, return the number of range sums that lie in [lower, 
 * upper] inclusive.
 * 
 *     Range sum S(i, j) is defined as the sum of the elements in nums between indices 
 * i and 
 *     j (i ≤ j), inclusive.
 * 
 *     Note:
 *     A naive algorithm of O(n2) is trivial. You MUST do better than that.
 * 
 *     Example:
 *     Given nums = [-2, 5, -1], lower = -2, upper = 2,
 *     Return 3.
 *     The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test 
 * cases.
 *               
 ***************************************************************************************/


/*
 *  At first of all, we can do preprocess to calculate the prefix sums 
 * 
 *      S[i] = S(0, i), then S(i, j) = S[j] - S[i]. 
 *  
 *  Note: S(i, j) as the sum of range [i, j) where j exclusive and j > i. 
 *
 *  With these prefix sums, it is trivial to see that with O(n^2) time we can find all S(i, j) 
 *  in the range [lower, upper]
 *
 *      int countRangeSum(vector<int>& nums, int lower, int upper) {
 *        int n = nums.size();
 *        long[] sums = new long[n + 1];
 *        for (int i = 0; i < n; ++i) {
 *            sums[i + 1] = sums[i] + nums[i];
 *        }
 *        int ans = 0;
 *        for (int i = 0; i < n; ++i) {
 *            for (int j = i + 1; j <= n; ++j) {
 *                if (sums[j] - sums[i] >= lower && sums[j] - sums[i] <= upper) {
 *                    ans++;
 *                }
 *            }
 *        }
 *        delete []sums;
 *        return ans;
 *      }
 * 
 *  The above solution would get time limit error.
 *
 *  Recall `count smaller number after self` where we encountered the problem
 *
 *      count[i] = count of nums[j] - nums[i] < 0 with j > i
 *
 *  Here, after we did the preprocess, we need to solve the problem
 *
 *      count[i] = count of a <= S[j] - S[i] <= b with j > i   
 *
 *  In other words, if we maintain the prefix sums sorted, and then are able to find out 
 *  - how many of the sums are less than 'lower', say num1, 
 *  - how many of the sums are less than 'upper + 1', say num2, 
 *  Then 'num2 - num1' is the number of sums that lie within the range of [lower, upper].
 *
 */

class Node{
    public:
        long long val;
        int cnt; //amount of the nodes
        Node *left, *right;
        Node(long long v):val(v), cnt(1), left(NULL), right(NULL) {}
};

// a tree stores all of prefix sums
class Tree{
    public:
        Tree():root(NULL){ }
        ~Tree() { freeTree(root); }
        
        void Insert(long long val) {
            Insert(root, val);
        }
        int LessThan(long long sum, int val) {
            return LessThan(root, sum, val, 0);
        }
        
    private:
        Node* root;
        
        //general binary search tree insert algorithm
        void Insert(Node* &root, long long val) {
            if (!root) {
                root = new Node(val);
                return;
            }
            
            root->cnt++;
            
            if (val < root->val ) {
                Insert(root->left, val);
            }else if (val > root->val) {
                Insert(root->right, val);
            }
        }
        //return how many of the sums less than `val`
        //  -  `sum` is the new sums which hasn't been inserted
        //  -  `val` is the `lower` or `upper+1`
        int LessThan(Node* root, long long sum, int val, int res) {
            
            if (!root) return res;

            if ( sum - root->val < val) {
                //if (sum[j, i] < val), which means all of the right branch must be less than `val` 
                //so we add the amounts of sums in right branch, and keep going the left branch.
                res += (root->cnt - (root->left ? root->left->cnt : 0) );
                return LessThan(root->left, sum, val, res);
            }else if ( sum - root->val > val) {
                //if (sum[j, i] > val), which means all of left brach must be greater than `val`
                //so we just keep going the right branch.
                return LessThan(root->right, sum, val, res);
            }else {
                //if (sum[j,i] == val), which means we find the correct place, 
                //so we just return the the amounts of right branch.]
                return res + (root->right ? root->right->cnt : 0);
            }
        }
        void freeTree(Node* root){
            if (!root) return;
            if (root->left) freeTree(root->left);
            if (root->right) freeTree(root->right);
            delete root;
        }
        
};



class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        Tree tree;
        tree.Insert(0);
        long long sum = 0;
        int res = 0;
        
        for (int n : nums) {
            sum += n;
            int lcnt = tree.LessThan(sum, lower);
            int hcnt = tree.LessThan(sum, upper + 1);
            res += (hcnt - lcnt);
            tree.Insert(sum);
        }

        return res;
    }
};
