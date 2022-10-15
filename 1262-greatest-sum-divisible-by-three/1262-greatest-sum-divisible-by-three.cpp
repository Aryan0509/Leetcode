class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>dp(3);
        for(auto it:nums)
        {
            for(auto i:vector<int>(dp))
            {
                dp[(i+it)%3]=max(dp[(i+it)%3],i+it);
            }
        }
        return dp[0];
    }
};