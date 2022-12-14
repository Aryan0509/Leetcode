class Solution {
public:
    
    void markvisited( vector<vector<int>>&grid,int s,vector<int>&visited,int &count)
    {
        visited[s]=1;
        
        for(auto x:grid[s])
        {
            if(visited[x]==0)
            {
                count++;
                markvisited(grid,x,visited,count);
            }
        }
        
    }
    
    
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>>grid(n);
        for(int i=0;i<n-1;i++)
        {
            int x1,y1;
            x1=stones[i][0];
            y1=stones[i][1];
            for(int j=i+1;j<n;j++)
            {
                int x2,y2;
                x2=stones[j][0];
                y2=stones[j][1];
                if(x1==x2 or y1==y2)
                {
                    grid[i].push_back(j);
                    grid[j].push_back(i);
                }
            }
        }
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                markvisited(grid,i,visited,count);
            }
        }
        return count;
    }
};