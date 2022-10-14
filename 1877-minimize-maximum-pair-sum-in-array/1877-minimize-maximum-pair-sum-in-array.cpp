class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=0;
        int maxv=INT_MIN;
        int e=nums.size()-1;
        while(s<e)
        {
            maxv=max(maxv,nums[s++]+nums[e--]);
        }
        return maxv;
    }
};