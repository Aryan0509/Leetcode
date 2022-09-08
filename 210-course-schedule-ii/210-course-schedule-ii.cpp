class Solution {
public:
    void rundfs(vector<vector<int>>&grid,int s,vector<int>&isdone,vector<int>&ans)
    {
        for(auto it:grid[s])
        {
            if(isdone[it]==0)
            {
                rundfs(grid,it,isdone,ans);
            }
        }
        ans.push_back(s);
        isdone[s]=1;
    }
    
    bool ispresent(vector<vector<int>>&grid,int s,vector<int>&visited,vector<int>&recst)
    {
        visited[s]=1;
        recst[s]=1;
        for(auto it:grid[s])
        {
            if(visited[it]==0 and ispresent(grid,it,visited,recst))
                return true;
            if(recst[it]==1)
                return true;
        }
        recst[s]=0;
        return false;
    }
    
    
    bool iscyle(vector<vector<int>>&grid,int n)
    {
        vector<int>visited(n,0);
        vector<int>recst(n,0);
        for(int i=0;i<n;i++)
        {
            if(ispresent(grid,i,visited,recst))
            {
                return true;
            }
        }
        return false;
            
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int n=numCourses;
        vector<vector<int>>grid(n);
        int k=pre.size();
        for(int i=0;i<k;i++)
        {
            grid[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int>ans;
        if(iscyle(grid,n))
        {
            return ans;
        }
        vector<int>isdone(n,0);
        for(int i=0;i<n;i++)
        {
            if(isdone[i]==0)
            {
                rundfs(grid,i,isdone,ans);
            }
        }
        return ans;
    }
};