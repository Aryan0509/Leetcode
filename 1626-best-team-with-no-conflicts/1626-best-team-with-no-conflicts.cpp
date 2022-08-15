class Solution {
public:
    
    static bool cmp(pair<int,int>p1,pair<int,int>p2)
    {
        if(p1.second==p2.second)
        {
            return p1.first<p2.first;
        }
        return p1.second<p2.second;
    }
    
    int findmax(vector<pair<int,int>>&p,int s,int lsp,int n,vector<vector<int>>&dp)
    {
     
        if(s>=n)
            return 0;
           int ans;
        if(lsp==-1){
            if(dp[s][n+3]!=-1)
                return dp[s][n+3];
            ans= max(p[s].first+findmax(p,s+1,s,n,dp),findmax(p,s+1,lsp,n,dp));
            dp[s][n+3]=ans;
            return ans;
        }
        if(dp[s][lsp]!=-1)
            return dp[s][lsp];
     
        if(p[s].second==p[lsp].second)
        {
                ans= max(p[s].first+findmax(p,s+1,s,n,dp),findmax(p,s+1,lsp,n,dp));
            dp[s][lsp]=ans;
            return ans;
        }
        if(p[s].first<p[lsp].first)
        {
            ans= findmax(p,s+1,lsp,n,dp);
            dp[s][lsp]=ans;
            return ans;
        }
        dp[s][lsp]= max(p[s].first+findmax(p,s+1,s,n,dp),findmax(p,s+1,lsp,n,dp));
        return dp[s][lsp];
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>p;
        int n=scores.size();
        vector<vector<int>>dp(n+5,vector<int>(n+5,-1));
        for(int i=0;i<n;i++)
        {
            p.push_back({scores[i],ages[i]});
        }
        sort(p.begin(),p.end(),cmp);
        return findmax(p,0,-1,n,dp);
        
    }
};