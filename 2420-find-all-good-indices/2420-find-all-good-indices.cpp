class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>noninc(n);
        vector<int>nondec(n);
        noninc[0]=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<=nums[i-1])
                noninc[i]=noninc[i-1]+1;
            else noninc[i]=1;
        }
        nondec[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<=nums[i+1])
                nondec[i]=nondec[i+1]+1;
            else nondec[i]=1;
        }
        vector<int>ans;
        for(int i=1;i<n-1;i++)
        {
            if(noninc[i-1]>=k and nondec[i+1]>=k)
                ans.push_back(i);
        }
        return ans;
    }
};