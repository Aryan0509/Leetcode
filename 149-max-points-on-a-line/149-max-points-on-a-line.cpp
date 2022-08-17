class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        // map<int,set<double>>m;
        if(n==1)
            return 1;
        int max=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int x1=points[i][0];
            int y1=points[i][1];
            map<double,int>count; 
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
//         int max=INT_MIN;
//         for(auto it:m)
//         {
//             if(it.second>max)
//             {
//                 max=it.second;
//             }
//         }
//         max=2*max;
        
//         for(int i=1;i<n;i++)
//         {
//             if(i*(i+1)==max)
//                 return i+1;
//         }
        return max+1;
        
        
    }
};