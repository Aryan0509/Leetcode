class Solution {
public:
    
    static bool cmp(pair<int,int>p1,pair<int,int>p2)
    {
        if(p1.second==p2.second)
            return p1.first<p2.first;
       return p1.second>p2.second;
    }
    
    int earliestFullBloom(vector<int>& plant, vector<int>& grow) {
        vector<pair<int,int>>p;
        int n=plant.size();
        for(int i=0;i<n;i++)
        {
            p.push_back({plant[i],grow[i]+1});
        }
        sort(p.begin(),p.end(),cmp);
        int days=-1;
        int maxx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            days+=p[i].first;
            maxx=max(maxx,days+p[i].second);
        }
            return maxx;
 
        
    }
};