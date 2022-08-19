class Solution {
public:
    void findsubsets(vector<int>& nums,vector<vector<int>>&ans,vector<int>&v,int s)
    {
        if(s==nums.size())
        {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[s]);
        findsubsets(nums,ans,v,s+1);
        v.pop_back();
        findsubsets(nums,ans,v,s+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        findsubsets(nums,ans,v,0);
        return ans;
    }
};