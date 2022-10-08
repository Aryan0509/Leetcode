class Solution {
public:
    static bool cmp(pair<int,int>p1,pair<int,int>p2)
    {
        if(p1.first==p2.first)
            return p1.second<p2.second;
        return p1.first<p2.first;
    }
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long>sti(n);
        vector<long long>bsti(n);
        sti[0]=nums[0];
        bsti[n-1]=0;
        for(int i=1;i<n;i++)
        {
            sti[i]=nums[i]+sti[i-1];
            bsti[n-i-1]=nums[n-i]+bsti[n-i];
        }
        vector<int>diff(n);
        for(int i=0;i<n;i++)
        {
            if(i==n-1)
            {
                diff[i]=sti[i]/n;
            }
            else
            diff[i]=abs(sti[i]/(i+1)-bsti[i]/(n-i-1));
        }
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++)
        {
            p.push_back({diff[i],i});
        }
        sort(p.begin(),p.end(),cmp);
        return p[0].second;
    }
};