class Solution {
public:
    
    void rundfs(vector<int>& nums, int target,int s,int sum,int &count,int n)
    {
        
        if(s==n)
        {
            if(sum==target)
                count++;
            return;
        }
        rundfs(nums,target,s+1,sum+nums[s],count,n);
        rundfs(nums,target,s+1,sum-nums[s],count,n);
        
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int count=0;
        int sum=0;
        rundfs(nums,target,0,sum,count,n);
        return count;
    }
};