class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int it=0;it<nums.size();it++)
        {
            if(nums[it]!=it)
                return it;
        }
        return nums.size();
    }
};