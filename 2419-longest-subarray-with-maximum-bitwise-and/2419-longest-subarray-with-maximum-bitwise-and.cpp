class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxe=*max_element(nums.begin(),nums.end());
        int maxl=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==maxe)
            {
                int j=i+1;
                while(j<nums.size() and nums[j]==maxe)
                    j++;
                maxl=max(maxl,j-i);
                i=j-1;
            }
        }
        return maxl;
    }
};