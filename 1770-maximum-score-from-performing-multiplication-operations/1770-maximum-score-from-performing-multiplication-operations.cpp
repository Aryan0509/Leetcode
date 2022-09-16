class Solution {
public:
    
    int solve(vector<int>& nums, vector<int>& multiplier,int s,int e,int i,int &m,vector<vector<int>>&dp)
    {
        if(i==m or e<s)
            return 0;
        if(dp[s][i]!=INT_MIN/2)
            return dp[s][i];
    
        if(nums[s]*multiplier[i]+solve(nums,multiplier,s+1,e,i+1,m,dp)>=nums[e]*multiplier[i]+solve(nums,multiplier,s,e-1,i+1,m,dp))
        {
            dp[s][i]= nums[s]*multiplier[i]+solve(nums,multiplier,s+1,e,i+1,m,dp);
            
            return dp[s][i];
        }
        else {
            
            dp[s][i]=nums[nums.size()-1-i
                         +s]*multiplier[i]+solve(nums,multiplier,s,e-1,i+1,m,dp);
            
            return dp[s][i];
        }
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int score=0;
        int e=nums.size()-1;
        int m=multipliers.size();
        vector<vector<int>>dp(m,vector<int>(m,INT_MIN/2));
        int s=0;
        int i=0;
        return solve(nums,multipliers,0,e,0,m,dp);
        
     
    }
};