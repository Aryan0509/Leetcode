class Solution {
public:
    int findmin(vector<int>& arr,int s,int row,int &n,vector<vector<int>>&dp)
    {   int ans;
        if(s==n-1)
            return 0;
        if(dp[s][row]!=-1)
            return dp[s][row];
        if(arr[s+1]!=row)
        {
            dp[s][row]=findmin(arr,s+1,row,n,dp);
            return dp[s][row];
        }
    
        else {
            if(row==1)
            {
                if(arr[s]==0)
                {
                    ans= min(1+findmin(arr,s,2,n,dp),1+findmin(arr,s,3,n,dp));
                }
                else if(arr[s]==2)
                {
                    ans= 1+findmin(arr,s,3,n,dp);
                }
                else ans= 1+findmin(arr,s,2,n,dp);
            }
           else if(row==2)
            {
                if(arr[s]==0)
                {
                    ans= min(1+findmin(arr,s,3,n,dp),1+findmin(arr,s,1,n,dp));
                }
                else if(arr[s]==1)
                {
                    ans= 1+findmin(arr,s,3,n,dp);
                }
                else ans= 1+findmin(arr,s,1,n,dp);
            }
            else if(row==3)
            {
                if(arr[s]==0)
                {
                    ans= min(1+findmin(arr,s,2,n,dp),1+findmin(arr,s,1,n,dp));
                }
                else if(arr[s]==2)
                {
                    ans= 1+findmin(arr,s,1,n,dp);
                }
                else ans= 1+findmin(arr,s,2,n,dp);
            }
            dp[s][row]=ans;
            return ans;
        }
        return 0;
    }
    
    
    int minSideJumps(vector<int>& arr) {
        int ans;
        int n=arr.size();
        vector<vector<int>>dp(n+2,vector<int>(4,-1));
        ans=findmin(arr,0,2,n,dp);
        return ans;
    }
};