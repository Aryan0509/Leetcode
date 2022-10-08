class Solution {
public:
    static bool cmp(pair<int,int>p1,pair<int,int>p2)
    {
        return p1.first-p1.second<p2.first-p2.second;
    }
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) {
        vector<pair<int,int>>p;
        int n=capacity.size();
        for(int i=0;i<n;i++)
        {
            p.push_back({capacity[i],rocks[i]});
        }
        sort(p.begin(),p.end(),cmp);
        int i=0;
        int count=0;
        while(ar>0 and i<n)
        {
            int d=p[i].first-p[i].second;
            if(d>ar)
            {
                return count;
            }
            if(d==ar)
                return count+1;
            else{
                ar-=d;
                count++;
            }
            i++;
        }
        return count;
    }
};