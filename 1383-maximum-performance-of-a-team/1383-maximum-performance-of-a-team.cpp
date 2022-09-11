class Solution {
public:
    int mod=1000000007;
    static bool cmp(pair<int,int>&p1,pair<int,int>&p2)
    {
        if(p1.first==p2.first)
        {
            return p1.second>p2.second;
        }
        return p1.first>p2.first;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++)
        {
            p.push_back({efficiency[i],speed[i]});
        }
        sort(p.begin(),p.end(),cmp);
        long long speedsum=0;
        long long ans=INT_MIN;
        priority_queue<int,vector<int>,greater<int>>q;
        for(auto it:p)
        {
            int s=it.second;
            int e=it.first;
            q.push(s);
            speedsum+=s;
            if(q.size()>k)
            {
                speedsum-=q.top();
                q.pop();
            }
            ans=max(ans,speedsum*e);
        }
        return ans%1000000007;
    }
};