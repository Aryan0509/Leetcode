class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end(),greater<int>());
        int n=nums.size();
        int sum=0;
        for(auto it:nums)
            sum+=it;
        int m=queries.size();
        vector<int>ans;
        for(int i=0;i<m;i++)
        {
            int q=queries[i];
            int x=sum;
            int k=0;
            int count=0;
            while(x>q)
            {
                x-=nums[k++];
                count++;
            }
            ans.push_back(n-count);
        }
        return ans;
    }
    
};