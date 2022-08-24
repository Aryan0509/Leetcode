class Solution {
public:
    bool ispossible(vector<int>&nums,int s,int csum,int sum,vector<vector<int>>&dp)
    {if(s>=nums.size())
            return false;
        if(dp[s][sum]!=-1)
            return dp[s][sum];
        if(csum==sum){
            dp[s][sum]=1;
             return true;
        }
           bool ans;
        
       ans= ispossible(nums,s+1,csum+nums[s],sum-nums[s],dp) or ispossible(nums,s+1,csum,sum,dp);
     dp[s][sum]=ans;
     return ans;
    }
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums)
            sum+=it;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        
        return ispossible(nums,0,0,sum,dp);
    }
};