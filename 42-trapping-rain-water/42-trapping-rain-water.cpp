class Solution {
public:
    int trap(vector<int>& heights) {
        int n=heights.size();
        vector<int>rmax(n);
        vector<int>lmax(n);
        rmax[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            rmax[i]=max(heights[i+1],rmax[i+1]);
        }
        lmax[0]=0;
        for(int i=1;i<n;i++)
        {
            lmax[i]=max(lmax[i-1],heights[i-1]);
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=max(min(lmax[i],rmax[i])-heights[i],0);
        }
        return sum;
        
    }
};