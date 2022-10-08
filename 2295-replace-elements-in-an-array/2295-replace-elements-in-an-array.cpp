class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            m[nums[i]]=i;
        }
        for(auto it:operations)
        {
            nums[m[it[0]]]=it[1];
            m[it[1]]=m[it[0]];
        }
        return nums;
    }
};