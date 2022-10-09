class Solution {
public:
    vector<int>reduce(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>ans(n/2);
        for(int i=0;i<n/2;i++)
        {
            if(i%2==0)
            {
                ans[i]=min(nums[2*i],nums[2*i+1]);
            }
            else ans[i]=max(nums[2*i],nums[2*i+1]);
        }
        return ans;
    }
    int minMaxGame(vector<int>& nums) {
        while(nums.size()>1)
        {
            nums=reduce(nums);
        }
        return nums[0];
    }
};