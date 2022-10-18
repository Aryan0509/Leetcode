//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int find(int i,int j,string &s1,string &s2,vector<vector<int>>&dp)
    {
        if(i==s1.length() or j==s2.length())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s1[i]!=s2[j])
        {
            dp[i][j]=0;
            return 0;
        }
        else {
            int ans;
            ans=1+find(i+1,j+1,s1,s2,dp);
            dp[i][j]=ans;
            return ans;
        }
        return 0;
    }
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int maxx=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                maxx=max(maxx,find(i,j,s1,s2,dp));
            }
        }
        return maxx;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends