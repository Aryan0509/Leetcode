class Solution {
public:
    
    long long fact(int n,vector<long long>&dp)
    {
        if(n==0 or n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        long long ans=n*fact(n-1,dp);
        dp[n]=ans;
        return ans;
    }
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        vector<long long>dp(100001,-1);
        long long sum=0;
        unordered_map<double,int>m;
        int x1,x2,y1,y2;
        for(int i=0;i<n;i++)
        {   
            x1=points[i][0];
            y1=points[i][1];
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {   
                    x2=points[j][0];
                    y2=points[j][1];
                    double d;
                    d=double(sqrt(((x2-x1)*(x2-x1))+(y2-y1)*(y2-y1)));
                    m[d]++;
                }
            }
            for(auto it:m)
            {
                if(it.second>1)
                {
                    sum+=fact(it.second,dp)/fact(it.second-2,dp);
                }
            }
            m.clear();
        }
        return sum;
    }
};