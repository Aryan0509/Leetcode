class Solution {
public:
    void dfspacific(vector<vector<int>>& heights,int i,int j,vector<vector<int>>& pv,vector<vector<int>>&pacific)
    {   
        int n=heights.size();
        int m=heights[0].size();
        int c=heights[i][j];
        pacific[i][j]=1;
        pv[i][j]=1;
        if(i+1<n and heights[i+1][j]>=c and pv[i+1][j]==0)
        {
            dfspacific(heights,i+1,j,pv,pacific);
        }
        if(i-1>=0 and heights[i-1][j]>=c and pv[i-1][j]==0)
        {
            dfspacific(heights,i-1,j,pv,pacific);
        }
        if(j+1<m and heights[i][j+1]>=c and pv[i][j+1]==0)
        {
            dfspacific(heights,i,j+1,pv,pacific);
        }
        if(j-1>=0 and heights[i][j-1]>=c and pv[i][j-1]==0)
        {
            dfspacific(heights,i,j-1,pv,pacific);
        } 
    }
    void dfsatlantic(vector<vector<int>>& heights,int i,int j,vector<vector<int>>& pv,vector<vector<int>>&pacific)
    {   
        int n=heights.size();
        int m=heights[0].size();
        int c=heights[i][j];
        pacific[i][j]=1;
        pv[i][j]=1;
        if(i+1<n and heights[i+1][j]>=c and pv[i+1][j]==0)
        {
            dfspacific(heights,i+1,j,pv,pacific);
        }
        if(i-1>=0 and heights[i-1][j]>=c and pv[i-1][j]==0)
        {
            dfspacific(heights,i-1,j,pv,pacific);
        }
        if(j+1<m and heights[i][j+1]>=c and pv[i][j+1]==0)
        {
            dfspacific(heights,i,j+1,pv,pacific);
        }
        if(j-1>=0 and heights[i][j-1]>=c and pv[i][j-1]==0)
        {
            dfspacific(heights,i,j-1,pv,pacific);
        } 
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>pacific(n,vector<int>(m,-1));
        vector<vector<int>>atlantic(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            pacific[i][0]=1;
            atlantic[i][m-1]=1;
            
        }
        for(int j=0;j<m;j++)
        {
            pacific[0][j]=1;
            atlantic[n-1][j]=1;
        }  
      
        vector<vector<int>>pv(n,vector<int>(m,0));
        vector<vector<int>>av(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   
                if(pv[i][j]==0 and pacific[i][j]==1)
                {
                    dfspacific(heights,i,j,pv,pacific);
                }
            }
        } 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   
                if(av[i][j]==0 and atlantic[i][j]==1)
                {
                    dfsatlantic(heights,i,j,av,atlantic);
                }
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(atlantic[i][j]==1 and pacific[i][j]==1)
                    ans.push_back({i,j});
            }
            // cout<<endl;
        }

        return ans;
            
    }
};