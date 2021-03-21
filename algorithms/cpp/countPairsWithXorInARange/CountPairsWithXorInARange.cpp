// Source : https://leetcode.com/problems/count-pairs-with-xor-in-a-range/
// Author : Hao Chen
// Date   : 2021-03-21

/***************************************************************************************************** 
 *
 * Given a (0-indexed) integer array nums and two integers low and high, return the number of nice 
 * pairs.
 * 
 * A nice pair is a pair (i, j) where 0 <= i < j < nums.length and low <= (nums[i] XOR nums[j]) <= 
 * high.
 * 
 * Example 1:
 * 
 * Input: nums = [1,4,2,7], low = 2, high = 6
 * Output: 6
 * Explanation: All nice pairs (i, j) are as follows:
 *     - (0, 1): nums[0] XOR nums[1] = 5 
 *     - (0, 2): nums[0] XOR nums[2] = 3
 *     - (0, 3): nums[0] XOR nums[3] = 6
 *     - (1, 2): nums[1] XOR nums[2] = 6
 *     - (1, 3): nums[1] XOR nums[3] = 3
 *     - (2, 3): nums[2] XOR nums[3] = 5
 * 
 * Example 2:
 * 
 * Input: nums = [9,8,4,2,1], low = 5, high = 14
 * Output: 8
 * Explanation: All nice pairs (i, j) are as follows:
 *     - (0, 2): nums[0] XOR nums[2] = 13
 *     - (0, 3): nums[0] XOR nums[3] = 11
 *     - (0, 4): nums[0] XOR nums[4] = 8
 *     - (1, 2): nums[1] XOR nums[2] = 12
 *     - (1, 3): nums[1] XOR nums[3] = 10
 *     - (1, 4): nums[1] XOR nums[4] = 9
 *     - (2, 3): nums[2] XOR nums[3] = 6
 *     - (2, 4): nums[2] XOR nums[4] = 5
 * 
 * Constraints:
 * 
 * 	1 <= nums.length <= 2 * 10^4
 * 	1 <= nums[i] <= 2 * 10^4
 * 	1 <= low <= high <= 2 * 10^4
 ******************************************************************************************************/

/*
The problem can be solved using Trie. 

The idea is to iterate over the given array and for each array element, 
count the number of elements present in the Trie whose bitwise XOR with 
the current element is less than K and insert the binary representation 
of the current element into the Trie. Finally, print the count of pairs 
having bitwise XOR less than K. Follow the steps below to solve the problem:

  - Create a Trie store the binary representation of each element of the given array.
  
  - Traverse the given array, and count the number of elements present in the Trie 
    whose bitwise XOR with the current element is less than K and insert the binary 
    representation of the current element.
    

Let's assume,  we have an array [A, B, C, D, E], all of number are 5 bits.

Find a pair is (X, E) such that X ^ E < K.  (Note: X could be A,B,C,D)

Now, let's say the binary of K = 11010. E = 01010.

from the left to right, 

1) Step One - the 1st bit

   K = 1 1 0 1 0
   E = 0 1 0 1 0
       ^
   X = 0 x x x x   ->  all of number with `0` as the 1st bit need be count.
   
2) Step Two - the 2nd bit 

   K = 1 1 0 1 0
   E = 0 1 0 1 0
         ^
   X = 1 1 x x x   ->  all of number with `1` as the 1st bit need be count.

3) Step Three - the 3rd bit

   K = 1 1 0 1 0
   E = 0 1 0 1 0
           ^
   X = 1 0 0 x x   ->  must be 0, and go to evaluate next bit

4) Step Four - the 4th bit

   K = 1 1 0 1 0
   E = 0 1 0 1 0
             ^
   X = 1 1 0 1 x   ->  all of number with `1` as the 1st bit need be count.
   
5) Step Five - the 5th bit

   K = 1 1 0 1 0
   E = 0 1 0 1 0
               ^
   X = 1 1 0 1 0   ->  must be 0, and go to evaluate next bit

So, all of number will be sum of (step one, two, four)
    
*/ 

const int LEVEL = 16; // 1 <= nums[i] <= 20000

struct TrieNode { 
    TrieNode *child[2];  // Stores binary represention of numbers  
    int cnt; // Stores count of elements present in a node
    TrieNode() { 
        child[0] = child[1] = NULL; 
        cnt = 0; 
    } 
}; 
 
 
// Function to insert a number into Trie 
void insertTrie(TrieNode *root, int n) { 
    // Traverse binary representation of X 
    for (int i = LEVEL; i >= 0; i--) { 
        // Stores ith bit of N 
        bool x = (n) & (1 << i); 
        // Check if an element already present in Trie having ith bit x
        if(!root->child[x]) { 
            // Create a new node of Trie. 
            root->child[x] = new TrieNode(); 
        } 
        // Update count of elements whose ith bit is x 
        root->child[x]->cnt += 1; 
        
        //Go to next level
        root = root->child[x]; 
    } 
} 


class Solution {
private:
    // Count elements in Trie whose XOR with N less than K 
    int countSmallerPairs(TrieNode * root,  int N, int K) { 
        // Stores count of elements whose XOR with N less than K 
        int cntPairs = 0; 
        // Traverse binary representation of N and K in Trie 
        for (int i = LEVEL; i >= 0 && root; i--) {                 
            bool x = N & (1 << i); // Stores ith bit of N 
            bool y = K & (1 << i); // Stores ith bit of K 

            // If the ith bit of K is 0 
            if (y == 0 ) { 
                // find the number which bit is same as N
                // so that they can be xored to ZERO
                root = root->child[x]; 
                continue;
            } 
            // If the ith bit of K is 1 
            // If an element already present in Trie having ith bit (x)
            if(root->child[x]) {
                // find the number which bit is same as N
                // so that they can be xored to ZERO. so it would be smaller than K
                cntPairs  += root->child[x]->cnt; 
            }
            //go to another way for next bit count
            root = root->child[1 - x]; 
        } 
        return cntPairs; 
    } 
public:
    int countPairs(vector<int>& nums, int low, int high) {
        
        TrieNode* root = new TrieNode();
        
        int cnt = 0;
        for (auto& num : nums) {
            cnt += countSmallerPairs(root, num, high + 1) - countSmallerPairs(root, num, low);
            insertTrie(root, num);
        }
        
        
        return cnt;
    }
};
