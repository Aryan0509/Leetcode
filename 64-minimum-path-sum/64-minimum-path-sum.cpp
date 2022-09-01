class Solution {
public:
    int solve(vector<vector<int>>& grid,vector<vector<int>>&dp,int r,int c,int &n,int &m)
    {
        if(r>=n or c>=m)
        {
            return INT_MAX/2;
        }
        if(r==n-1 and c==m-1)
        {
            dp[r][c]=grid[r][c];
            return grid[r][c];
        }
        if(dp[r][c]!=-1)
        {
            return dp[r][c];
        }
        int o1=solve(grid,dp,r+1,c,n,m);
        int o2=solve(grid,dp,r,c+1,n,m);
        dp[r][c]=grid[r][c]+min(o1,o2);
        return dp[r][c];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(grid,dp,0,0,n,m);
    }
};