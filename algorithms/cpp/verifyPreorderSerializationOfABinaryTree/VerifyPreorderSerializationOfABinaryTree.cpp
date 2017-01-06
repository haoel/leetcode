// Source : https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
// Author : Hao Chen
// Date   : 2017-01-06

/*************************************************************************************** 
 *
 * One way to serialize a binary tree is to use pre-order traversal. When we encounter 
 * a non-null node, we record the node's value. If it is a null node, we record using a 
 * sentinel value such as #.
 * 
 *      _9_
 *     /   \
 *    3     2
 *   / \   / \
 *  4   1  #  6
 * / \ / \   / \
 * # # # #   # #
 * 
 * For example, the above binary tree can be serialized to the string 
 * "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
 * 
 * Given a string of comma separated values, verify whether it is a correct preorder 
 * traversal serialization of a binary tree. Find an algorithm without reconstructing 
 * the tree.
 * 
 * Each comma separated value in the string must be either an integer or a character 
 * '#' representing null pointer.
 * 
 * You may assume that the input format is always valid, for example it could never 
 * contain two consecutive commas such as "1,,3".
 * 
 * Example 1:
 * "9,3,4,#,#,1,#,#,2,#,6,#,#"
 * Return true
 * Example 2:
 * "1,#"
 * Return false
 * Example 3:
 * "9,#,#,1"
 * Return false
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test 
 * cases.
 ***************************************************************************************/

class Solution {
public:

    // we know the following facts:
    //   1) if we met a non-null node, then this node will generate two child node.
    //   2) if we met a null node, then this node will generate zero child node.
    //
    // so the idea is, 
    //   1) we can have a counter to calculate how many node we are going to expect 
    //   2) once we have the expected node, then we can decrease the counter.
    //   3) finally, we will check the counter is zero or not.
    //
    // the algorithm as below:
    //   1) when we meet a non-null node, just simply do `counter++`. because:
    //      1.1) we will expect 2 more node after, then we do `counter += 2`. 
    //      1.2) but the current node also meet the expection of parent node , so, it need remove 1 in counter.
    //           finally, the `counter = counbter + 2 -1`
    //   2) when we meet a null node, just simply do `counter--`.
    
    bool isValidSerialization(string preorder) {
        vector<string> list;
        split(preorder, ',', list);
        //we initailize the counter as 1, 
        //because we expect at lease 1 node in the tree.
        int node_expected = 1;
        for (auto node : list) {
            if (node_expected == 0) return false;
            node == "#" ? node_expected-- : node_expected++;
        }
        return node_expected == 0;
    }
    
    void split(const string &s, char delim, vector<string> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
    }
};
