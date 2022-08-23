class Solution {
public:
    int solve(vector<vector<int>>& grid,int s,int r1,int r2, vector<vector<vector<int>>>&dp,int &m)
    {  
        if(s==grid.size()-1)
        {
            return grid[s][r1]+grid[s][r2];
        }
        if(dp[s][r1][r2]!=-1)
            return dp[s][r1][r2];
        int maxx=INT_MIN;
        vector<int>visited(m,0);
        for(int i=-1;i<2;i++)
        {   
            if(r1+i>=0 and r1+i<m)
            {
                visited[r1+i]=1;
                for(int j=-1;j<2;j++)
                {
                    if(r2+j<m and r2+j>=0 and visited[r2+j]==0 )
                    {
                        maxx=max(maxx,solve(grid,s+1,r1+i,r2+j,dp,m));
                    }

                }
                visited[r1+i]=0;
            }
        }
        dp[s][r1][r2]= maxx+grid[s][r1]+grid[s][r2];
        return dp[s][r1][r2];
    }
 
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        int ans;
        ans=solve(grid,0,0,m-1,dp,m);
        return ans;
    }
};