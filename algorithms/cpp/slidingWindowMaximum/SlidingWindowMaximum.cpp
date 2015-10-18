// Source : https://leetcode.com/problems/sliding-window-maximum/
// Author : Hao Chen
// Date   : 2015-07-19

/********************************************************************************** 
 * 
 * Given an array nums, there is a sliding window of size k which is moving from the 
 * very left of the array to the very right. You can only see the k numbers in the 
 * window. Each time the sliding window moves right by one position.
 * 
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 *
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * 
 * Therefore, return the max sliding window as [3,3,5,5,6,7].
 * 
 * Note: 
 * You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty 
 * array.
 * 
 * Follow up:
 * Could you solve it in linear time?
 * 
 *   How about using a data structure such as deque (double-ended queue)?
 *   The queue size need not be the same as the window’s size.
 *   Remove redundant elements and the queue should store only elements that need to be 
 * considered.
 * 
 **********************************************************************************/
#include <iostream>
#include <vector>
#include <deque>
#include <set>
using namespace std;

//O(nlog(k)
vector<int> maxSlidingWindow02(vector<int>& nums, int k) {
    vector<int> result;

    //using multiset for collecting the window data (O(nlog(k) time complexity)
    multiset<int> w;

    for(int i=0; i<nums.size(); i++) {
        //remove the left item which leaves window 
        if (i >= k) {
            w.erase(w.find(nums[i-k]));
        }
        //insert the right itme which enter the window
        w.insert(nums[i]);
        if (i>=k-1) {
            result.push_back(*w.rbegin());
        }
    }

    return result;
}

//O(n)
vector<int> maxSlidingWindow01(vector<int>& nums, int k) {
    vector<int> result;

    //using multiset for collecting the window data (O(nlog(k) time complexity)
    deque<int> q;

    for(int i=0; i<nums.size(); i++) {
        //remove the left item which leaves window 
        if (!q.empty() && q.front() == i - k) {
            q.pop_front();
        }
        //remove all num which less than current number from the back one by one
        while (!q.empty() && nums[q.back()] < nums[i]) {
            q.pop_back();
        }
        //insert the right itme which enter the window
        q.push_back(i);
        if (i>=k-1) {
            result.push_back(nums[q.front()]);
        }
    }

    return result;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    return maxSlidingWindow01(nums, k);
    return maxSlidingWindow02(nums, k);
}

void printVector( vector<int>& v ) {
    cout << "{ ";
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << (i==v.size() ? " ": ", ");
    }
    cout << "}" << endl;
}

int main(int argc, char** argv) 
{
    int a[] = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> nums(a, a+sizeof(a)/sizeof(a[0]));
    printVector(nums);
    vector<int> result = maxSlidingWindow(nums, k);
    printVector(result);
}
