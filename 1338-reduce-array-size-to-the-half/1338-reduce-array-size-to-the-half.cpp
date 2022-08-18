class Solution {
public:
    static bool cmp(pair<int,int>p1,pair<int,int>p2)
    {
        if(p1.second==p2.second)
        {
            return p1.first<p2.first;
        }
        return p1.second>p2.second;
    }
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        vector<pair<int,int>>p;
        for(auto it:m)
        {
            p.push_back({it.first,it.second});
        }
        sort(p.begin(),p.end(),cmp);
        int i=0;
        int count=0;
        while(count<n/2)
        {
            count+=p[i].second;
            i++;          
        }
        return i;
        
    }
};