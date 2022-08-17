class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n==1)
            return 1;
        int max=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int x1=points[i][0];
            int y1=points[i][1];
            unordered_map<double,int>count; 
            for(int j=0;j<n;j++)
            {   if(j==i)continue;
                
                int x2=points[j][0];
                int y2=points[j][1];
                double slope;
                if(x2==x1)
                    slope=INT_MAX;
                else
                {
                    slope=double(y2-y1)/double(x2-x1);
                }
                
                count[slope]++;
            }
            for(auto it:count)
            {
                if(it.second>max)
                {
                    max=it.second;;
                }
            }
        }
        return max+1;
        
        
    }
};