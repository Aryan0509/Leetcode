class Solution {
public:
    int findways(string &ss,int s,int n,vector<int>&dp)
    {
        if(s>=n)
            return 1;
        int ans;
        if(dp[s]!=-1)
            return dp[s];
        if(ss[s]=='*')
        {
            ans= findways(ss,s+2,n,dp);
            dp[s]=ans;
            return ans;
        }
        
        if(s<n-1 and ss[s+1]!='*' and stoi(ss.substr(s,2))<=26)
        {
            ans= findways(ss,s+2,n,dp) + findways(ss,s+1,n,dp);
            dp[s]=ans;
            return ans;
        }
        dp[s]= findways(ss,s+1,n,dp);
        return dp[s];
        
        
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        if(s[0]=='0')
            return 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0' and (s[i-1]!='1' and s[i-1]!='2'))
               return 0;
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i+1]=='0')
            {
                    s[i]='*';
                    s[i+1]='*';
                    i++;
            }
        }
        return findways(s,0,n,dp);
        
    
    }
};