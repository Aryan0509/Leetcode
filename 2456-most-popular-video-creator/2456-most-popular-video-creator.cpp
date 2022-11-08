class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string,pair<int,string>>m;
        int n=ids.size();
        map<string,pair<int,string>>mm;
        for(int i=0;i<n;i++)
        {
            m[creators[i]].first+=views[i];
            if(mm[creators[i]].first==0)
            {
                mm[creators[i]].second=ids[i];
                mm[creators[i]].first=views[i];
            }
            else if(views[i]>mm[creators[i]].first)
            {
                mm[creators[i]].second=ids[i];
                mm[creators[i]].first=views[i];
            }
            else if(views[i]==mm[creators[i]].first)
            {
                mm[creators[i]].second=min(ids[i],mm[creators[i]].second);
            }
            
            
        }
        
        int maxx=INT_MIN;
        for(auto it:m)
        {
            maxx=max(it.second.first,maxx);
        }
        
        vector<vector<string>>ans;
        for(auto it:m)
        {
            if(it.second.first==maxx)
            {
                ans.push_back({it.first,mm[it.first].second});
            }
        }
        return ans;
    }
};