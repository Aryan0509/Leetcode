class Solution {
public:
    
    int ispossible(vector<vector<int>>& grid,int s,int level,int &n,int &m)
    {
        if(level==n-1)
            return s;
        if(s==m-1)
        {
            if(grid[level+1][s]==1)
                return -1;
        }
        if(s==0)
        {
            if(grid[level+1][s]==-1)
                return -1;
        }
        if(grid[level+1][s]==1 and grid[level+1][s+1]==-1)
            return -1;
        if(grid[level+1][s]==-1 and grid[level+1][s-1]==1)
            return -1;
        
        if(grid[level+1][s]==1)
        {
            return ispossible(grid,s+1,level+1,n,m);
        }
        return ispossible(grid,s-1,level+1,n,m);
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>ans;
        for(int i=0;i<m;i++)
        {
            ans.push_back(ispossible(grid,i,-1,n,m));
        }
        return ans;
        
    }
};