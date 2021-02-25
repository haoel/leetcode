class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int ans=0;
        for(int i=0; i<nums.size(); i++){
            ans = ans^nums[i];
        }
        int xorr = ans &(~(ans-1));
        int res1=0,res2=0;
        for(int i=0;i<nums.size();i++){
            if(xorr & nums[i]) res1= res1^nums[i];
            else res2=res2^nums[i];
        }
        
        vector<int>v;
        v.push_back(res1);
        v.push_back(res2);
        
        return v;
    }
    
};
