class Solution {
public:
    static bool cmp(pair<string,int> p1,pair<string,int> p2)
    {
        if(p1.second==p2.second)
            return p1.first<p2.first;
        return p1.second>p2.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>m;
        for(auto it:words)
            m[it]++;
        vector<pair<string,int>>p;
        for(auto it:m)
        {
            p.push_back({it.first,it.second});
        }
        vector<string>ans;
        sort(p.begin(),p.end(),cmp);
        for(int i=0;i<k;i++)
        {
            ans.push_back(p[i].first);
        }
        return ans;
    }
};