// Source : https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Author : Calinescu Valentin
// Date   : 2016-05-22

/*************************************************************************************** 
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 * 
 * Note:
 * Each element in the result should appear as many times as it shows in both arrays.
 * The result can be in any order.
 * 
 * Follow up:
 * What if the given array is already sorted? How would you optimize your algorithm?
 * What if nums1's size is small compared to num2's size? Which algorithm is better?
 * What if elements of nums2 are stored on disk, and the memory is limited such that you
 * cannot load all elements into the memory at once?
 * 
 ***************************************************************************************/
 
 /* Solution
  * --------
  *
  * Follow up:
  * 
  * 1)If the given array is already sorted we can skip the sorting.
  * 
  * 2)If nums1 is significantly smaller than nums2 we can only sort nums1 and then binary
  * search every element of nums2 in nums1 with a total complexity of (MlogN) or if nums2
  * is already sorted we can search every element of nums1 in nums2 in O(NlogM)
  *
  * 3)Just like 2), we can search for every element in nums2, thus having an online
  * algorithm.
  */
  
class Solution { // O(NlogN + MlogM)
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());//we sort both vectors in order to intersect
        sort(nums2.begin(), nums2.end());//them later in O(N + M), where N = nums1.size()
        vector <int> solution;                                         //M = nums2.size() 
        int index = 0;
        bool finished = false;
        for(int i = 0; i < nums1.size() && !finished; i++)
        {
            while(index < nums2.size() && nums1[i] > nums2[index])//we skip over the
                index++;//smaller elements in nums2
            if(index == nums2.size())//we have reached the end of nums2 so we have no more
                finished = true;//elements to add to the intersection
            else if(nums1[i] == nums2[index])//we found a common element
            {
                solution.push_back(nums1[i]);
                index++;
            }
        }
        return solution;
    }
};
