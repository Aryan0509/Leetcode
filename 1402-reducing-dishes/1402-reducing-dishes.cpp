class Solution {
public:
    int solve(vector<pair<int,int>>&p,int s,int inc,vector<vector<int>>&dp)
{
    if(s==p.size())
    return 0;
    if(inc>s)
    return 0;
        
        if(dp[s][inc]!=-1)
            return dp[s][inc];
        int ans;
        ans= max((p[s].first*(p[s].second-inc))+solve(p,s+1,inc,dp),solve(p,s+1,inc+1,dp));
        dp[s][inc]=ans;
        return ans;
}

    int maxSatisfaction(vector<int>& s) {
       
        sort(s.begin(),s.end());
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
         vector<pair<int,int>>p;
          for(int i=0;i<s.size();i++)
          {

            p.push_back({s[i],i+1});
          }
             int ans;
        ans=solve(p,0,0,dp);
            return ans;
       
    }
};