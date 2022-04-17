class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans = {};
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hashMap.find(target - nums[i]) != hashMap.end())
            {
                ans.push_back(hashMap[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            hashMap[nums[i]] = i;
        }
        return ans;
    }
};
// https://leetcode.com/problems/two-sum/discuss/?currentPage=1&orderBy=hot&query=
