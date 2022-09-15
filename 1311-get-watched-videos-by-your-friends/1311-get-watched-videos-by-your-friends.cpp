class Solution {
public:
    static bool cmp(pair<string,int>p1,pair<string,int>p2)
    {
        if(p1.second==p2.second)
        {
            return p1.first<p2.first;
        }
        return p1.second<p2.second;
    }
    vector<string> watchedVideosByFriends(vector<vector<string>>& watched, vector<vector<int>>& friends, int id, int level) {
        int n=friends.size();
        int count=0;
        queue<int>q;
        q.push(id);
        vector<int>visited(n,0);
        visited[id]=1;
        q.push(-1);
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            if(x==-1)
            {
               count++;
               if(count==level)
               break;
                q.push(-1);
                continue;
            }
            for(auto it:friends[x])
            {
                if(visited[it]==0)
                {
                    visited[it]=1;
                    q.push(it);
                }
                
            }
        }
        map<string,int>m;
        while(q.size()>0)
        {
            int x=q.front();
            q.pop();
            for(auto it:watched[x])
            {
                m[it]++;
            }
        }
        vector<pair<string,int>>p;
        for(auto it:m)
        {
            p.push_back({it.first,it.second});
        }
        sort(p.begin(),p.end(),cmp);
        vector<string>ans;
        for(auto it:p)
        {
            ans.push_back(it.first);
        }
        return ans;
        
    }
};