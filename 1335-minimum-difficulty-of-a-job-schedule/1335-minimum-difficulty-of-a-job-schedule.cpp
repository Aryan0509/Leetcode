class Solution {
public:
    
    int solve(int s,int n,int d,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(s==n)
        {
            if(d==0)
                return 0;
            else return INT_MAX/2;
        }
        if(d==0)
            return INT_MAX/2;
        if(dp[s][d]!=-1)
            return dp[s][d];
        int cm=INT_MIN;
        int ans;
        int fans=INT_MAX;
        for(int i=s;i<n;i++)
        {
            if(n-i<d)
                break;
            cm=max(cm,arr[i]);
            ans=cm+solve(i+1,n,d-1,arr,dp);
            fans=min(ans,fans);
        }
        dp[s][d]=fans;
        return fans;
    }
    
    int minDifficulty(vector<int>& arr, int d) {
        int n=arr.size();
        if(d>n)
            return -1;
        vector<vector<int>>dp(n,vector<int>(d+1,-1));
        int ans=solve(0,n,d,arr,dp);
        return ans;
    }
};