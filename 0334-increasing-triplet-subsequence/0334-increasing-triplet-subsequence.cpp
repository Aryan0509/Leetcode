class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n);
        if(n<3)
            return false;
        left[0]=INT_MAX;
        for(int i=1;i<n;i++)
        {
            left[i]=min(left[i-1],nums[i-1]);
        }
        vector<int>right(n);
        right[n-1]=INT_MIN;
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],nums[i+1]);
        }
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]>left[i] and nums[i]<right[i])
                return true;
        }
        return false;
    }
};