class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>>m;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            m[nums[i]].push_back(i);
        }
        for(auto it:m)
        {
            if(it.second.size()>1)
            {
                int x=it.second.size();
                for(auto i=0;i<x-1;i++)
                {
                    if(it.second[i+1]-it.second[i]<=k)
                        return true;
                }
            }
        }
        return false;
    }
};