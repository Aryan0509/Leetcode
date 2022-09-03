class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans;
        int n=nums.size();
        int diff=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int n1=nums[i];
            int s=i+1;
            int e=n-1;
            while(s<e)
            {
                if(n1+nums[s]+nums[e]==target)
                {
                    return target;
                }
                if(n1+nums[s]+nums[e]<target)
                {
                    if(target-(n1+nums[s]+nums[e])<diff)
                    {
                        diff=target-n1+nums[s]+nums[e];
                        ans=n1+nums[s]+nums[e];
                    }
                    s++;
                }
                else{
                    
                    if(-target+n1+nums[s]+nums[e]<diff)
                    {
                        diff=-target+n1+nums[s]+nums[e];
                        ans=n1+nums[s]+nums[e];
                    }
                    e--;
                }
            }
        }
        return ans;
        
    }
};