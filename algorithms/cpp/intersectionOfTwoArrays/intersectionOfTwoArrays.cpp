// Source : https://leetcode.com/problems/intersection-of-two-arrays/
// Author : Calinescu Valentin
// Date   : 2016-05-20

/*************************************************************************************** 
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 * 
 * Note:
 * Each element in the result must be unique.
 * The result can be in any order.
 * 
 ***************************************************************************************/
class Solution {
public:
    set <int> inter1, inter2;//we use sets so as to avoid duplicates
    vector <int> solution;
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i < nums1.size(); i++)
            inter1.insert(nums1[i]);//get all of the unique elements in nums1 sorted
        for(int i = 0; i < nums2.size(); i++)
            if(inter1.find(nums2[i]) != inter1.end())//search inter1 in O(logN)
                inter2.insert(nums2[i]);//populate the intersection set
        for(set<int>::iterator it = inter2.begin(); it != inter2.end(); ++it)
            solution.push_back(*it);//copy the set into a vector
        return solution;
    }
};

/*
 * This Solution use one unordered_set 
 */
class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash_set(nums1.begin(), nums1.end());
        vector<int> res ;
        for (auto it& : nums2) {
            if (hash_set.count(it)) {
                res.push_back(it);
                hash_set.erase(it);
            }
        }
        return res;
    }
};











