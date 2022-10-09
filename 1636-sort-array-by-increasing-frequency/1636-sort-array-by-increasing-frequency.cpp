class Solution {
public:
    static bool cmp(pair<int,int>&p1,pair<int,int>&p2)
    {
        if(p1.second==p2.second)
            return p1.first>p2.first;
        return p1.second<p2.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>m;
        for(auto it:nums)
        {
            m[it]++;
        }
        vector<pair<int,int>>p;
        for(auto it:m)
        {
            p.push_back({it.first,it.second});
        } 
        sort(p.begin(),p.end(),cmp);
        vector<int>ans;
        for(auto it:p)
        {
            int n=it.first;
            int c=it.second;
            while(c--)
                ans.push_back(n);
        }
        return ans;
    }
};