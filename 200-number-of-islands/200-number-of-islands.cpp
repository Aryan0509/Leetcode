class Solution {
public:
   void solve(vector<vector<char>>& grid,vector<vector<int>>&visited,int n,int m,int i,int j)
    {
            if(i+1<n and grid[i+1][j]=='1' and visited[i+1][j]==0)
            {   visited[i+1][j]=1;
                solve(grid,visited,n,m,i+1,j);
            }
            // if(i+1<n and j+1<m and grid[i+1][j+1]=='1' and visited[i+1][j+1]==0)
            // {   visited[i+1][j+1]=1;
            //     solve(grid,visited,n,m,i+1,j+1);
            // }
            // if(i+1<n and j-1>=0 and grid[i+1][j-1]=='1' and visited[i+1][j-1]==0)
            // {   visited[i+1][j-1]=1;
            //     solve(grid,visited,n,m,i+1,j-1);
            // }
            if(j+1<m and grid[i][j+1]=='1' and visited[i][j+1]==0)
            {   visited[i][j+1]=1;
                solve(grid,visited,n,m,i,j+1);
            }
            if(j-1>=0 and grid[i][j-1]=='1' and visited[i][j-1]==0)
            {   visited[i][j-1]=1;
                solve(grid,visited,n,m,i,j-1);
            }
            // if(i-1>=0 and j-1>=0  and grid[i-1][j-1]=='1' and visited[i-1][j-1]==0)
            // {   visited[i-1][j-1]=1;
            //     solve(grid,visited,n,m,i-1,j-1);
            // }
            // if(i-1>=0 and j+1<m and grid[i-1][j+1]=='1' and visited[i-1][j+1]==0)
            // {   visited[i-1][j+1]=1;
            //     solve(grid,visited,n,m,i-1,j+1);
            // }
            if(i-1>=0 and grid[i-1][j]=='1' and visited[i-1][j]==0)
            {   visited[i-1][j]=1;
                solve(grid,visited,n,m,i-1,j);
            }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' and visited[i][j]==0)
                {
                    count++;
                    visited[i][j]=1;
                    solve(grid,visited,n,m,i,j);
                }
            }
        }
        return count;
    }
};