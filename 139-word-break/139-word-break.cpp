class Solution {
public:
    bool check(string &ss,unordered_map<string,int>&m,int s,vector<int>&dp)
    {
        if(s==ss.length())
            return true;
        if(dp[s]!=-1)
            return dp[s];
        int n=ss.length();
        for(int i=s;i<n;i++)
        {
            if(m.find(ss.substr(s,i-s+1))!=m.end())
            {
                if(check(ss,m,i+1,dp))
                {
                    dp[s]=1;
                     return true;
                }  
            }
        }
        dp[s]=0;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string,int>m;
        vector<int>dp(s.length()+2,-1);
        for(int i=0;i<wordDict.size();i++)
        {
            m[wordDict[i]]++;
        }
        return check(s,m,0,dp);
        
    }
};