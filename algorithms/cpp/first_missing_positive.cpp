// problem : https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        long int l = nums.size();
        if(l==0)
            return 1;
        if(l==1)
            return nums[0]==1?2:1;
        long int f=0,i;
        for( i=0;i<l;i++)
        {
            if(nums[i]<=0)
            {
                long int v= nums[i];
                nums[i]=nums[f];
                nums[f]=v;
                f++;
            }
        }
        long int st=f;
        cout<<f<<" ";
        for(int i=f;i<l;i++)
        {
            long int in = abs(nums[i])-1+st;
            cout<<in<<" ";
            if(in<l&&nums[in]>=0)
                nums[in]=-nums[in];
        }
        
        for(int i=st;i<l;i++)
            if(nums[i]>=0)
                return i+1-st;
        return l+1-st;
    }
};
