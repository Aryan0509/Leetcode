class Solution {
public:
    int mod=1000000007;
    int count(string &ss,int s,vector<int>&dp,map<char,int>&m)
    {
        if(s>=ss.length())
        {
            return 1;
        }
        if(dp[s]!=-1)
            return dp[s];
        int ans=0;
        char ch=ss[s];
        int k=m[ch];
        int j=s;
        while(j<ss.length() and j-s<k and ss[j]==ss[s])
        {
            ans=(ans%mod+count(ss,j+1,dp,m)%mod)%mod;
            j++;
        }
        dp[s]=ans;
        return ans;
    }
    
    int countTexts(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);
        map<char,int>m;
        m['2']=3;
        m['3']=3;
        m['4']=3;
        m['5']=3;
        m['6']=3;
        m['7']=4;
        m['8']=3;
        m['9']=4;
        
        return count(s,0,dp,m);
        
    }
};