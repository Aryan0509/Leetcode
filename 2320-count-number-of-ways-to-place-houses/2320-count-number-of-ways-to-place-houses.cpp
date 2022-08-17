class Solution {
public:
    int mod=1e9+7;
    int calc(int n,int isfill,vector<vector<long long>>&dp)
    {
        if(n==1)
            return 1;
        if(dp[n][isfill]!=-1)
            return dp[n][isfill];
     long long ans;
        if(isfill)
            ans= calc(n-1,0,dp)%mod;
        else ans=(calc(n-1,1,dp)%mod+calc(n-1,0,dp)%mod)%mod;
        
        dp[n][isfill]=ans;
        return ans;
    }
    int countHousePlacements(int n) {
        
         long long oneside;
        vector<vector<long long>>dp(n+1,vector<long long>(3,-1));
        oneside=calc(n,1,dp)+calc(n,0,dp);
        // cout<<oneside<<endl;
        oneside =((oneside%mod)*(oneside%mod))%mod;
        // ret
        // urn ((oneside%mod)*(oneside*mod))%mod;
        return oneside;
    }
};