class Solution {
public:
    void rundfs(vector<int>& cookies, int k,int &n,vector<vector<int>>&graph,int &minn,int s,vector<int>&sum)
    {
        if(s==n)
        {
            int ms=INT_MIN;
            for(auto it:sum)
            {
                ms=max(ms,it);
            }
            minn=min(minn,ms);
            return;
        }
        for(int i=0;i<k;i++)
        {
            graph[i].push_back(cookies[s]);
            if(sum[i]+cookies[s]>=minn)
                continue;
            sum[i]+=cookies[s];
            rundfs(cookies,k,n,graph,minn,s+1,sum);
            sum[i]-=cookies[s];
            graph[i].pop_back();
        }
        return ;
        
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<vector<int>>graph(k);
        int min=INT_MAX;
        int n=cookies.size();
        vector<int>sum(k,0);
        rundfs(cookies,k,n,graph,min,0,sum);
        return min;
    }
};