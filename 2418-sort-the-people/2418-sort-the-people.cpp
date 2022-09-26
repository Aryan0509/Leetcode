class Solution {
public:
    static bool cmp(pair<string,int>p1,pair<string,int>p2)
    {
        return p1.second>p2.second;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string,int>>p;
        for(int i=0;i<names.size();i++)
        {
            p.push_back({names[i],heights[i]});
        }
        sort(p.begin(),p.end(),cmp);
        for(int i=0;i<names.size();i++)
        {
            names[i]=p[i].first;
        }
        return names;
    }
};