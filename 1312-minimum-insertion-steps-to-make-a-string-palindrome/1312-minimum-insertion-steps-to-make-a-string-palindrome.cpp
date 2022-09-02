class Solution {
public:
    int findmin(string &ss,int s,int e,vector<vector<int>> &dp)
    {
        if(s==e)
        {
            return 0;
        }
        if(e-s==1)
        {
            if(ss[e]==ss[s])
                return 0;
            return 1;
        }
        
        if(dp[s][e]!=-1)
        {
            return dp[s][e];
        }
        int ans;
        if(ss[s]==ss[e])
        {
            ans=findmin(ss,s+1,e-1,dp);
            dp[s][e]=ans;
            return ans; 
        }
        else
        {
            int o1,o2;
            o1=findmin(ss,s,e-1,dp);
            o2=findmin(ss,s+1,e,dp);
            ans=1+min(o1,o2);
            dp[s][e]=ans;
            return ans;
        }
        return 0;
        
    }
    
    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return findmin(s,0,n-1,dp);
        
    }
};
