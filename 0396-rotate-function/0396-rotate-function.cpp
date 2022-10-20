class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int init=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            init+=i*nums[i];
        }
        int maxx=init;
        for(int i=1;i<n;i++)
        {
            init+=n*nums[i-1];
            init-=sum;
            maxx=max(maxx,init);
        }
        return maxx;
        
    }
};