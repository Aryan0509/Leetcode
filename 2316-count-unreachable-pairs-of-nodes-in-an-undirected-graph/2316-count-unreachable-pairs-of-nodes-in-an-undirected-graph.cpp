class Solution {
public:
    void rundfs(int s,vector<vector<int>>&grid,int n,vector<int>&visited,int &count)
    {
        count++;
        visited[s]=1;
        for(auto it:grid[s])
        {
            if(visited[it]==0)
            {
                rundfs(it,grid,n,visited,count);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>visited(n,0);
        vector<int>arr;
        vector<vector<int>>grid(n);
        for(auto it:edges)
        {
            grid[it[0]].push_back(it[1]);
            grid[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                int count=0;
                rundfs(i,grid,n,visited,count);
                arr.push_back(count);
            }
        }
        if(arr.size()==1)
            return 0;
        int nn=arr.size();
        long long sum=0;
        long long squaresum=0;
        for(auto it:arr)
        {
            sum+=it;
            squaresum+=long(it)*long(it);
        }
        sum=sum*sum;
        sum-=squaresum;
        return sum/2;
    }
};