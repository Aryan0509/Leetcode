class Solution {
public:
    int findmax(vector<int>& arr, int k,int s,int n,vector<vector<int>>&dp)
    {
        if(s>=n)
            return 0;
        if(s==n-1)
            return arr[s];
        if(dp[s][n]!=-1)
            return dp[s][n];
        int ans=INT_MIN;
        int maxi=INT_MIN;
        for(int i=1;i<=k;i++)
        {   if(s+i-1>=n)break;
            maxi=max(maxi,arr[s+i-1]);
            ans=max(ans,i*maxi+findmax(arr,k,s+i,n,dp));
        }
        dp[s][n]=ans;
        return ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return findmax(arr,k,0,n,dp);
    }
};