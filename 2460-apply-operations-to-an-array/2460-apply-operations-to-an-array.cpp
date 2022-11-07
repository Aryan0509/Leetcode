class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        vector<int>ans;
        int c=0;
        for(auto it:nums)
        {
            if(it==0)
            {
                c++;
            }
            else ans.push_back(it);
        }
        while(c--)
            ans.push_back(0);
        return ans;
    }
    
};