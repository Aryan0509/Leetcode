class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        map<int,int>m;
        for(auto it:nums)
        {
            if(m[it]>0)
            {
                ans.push_back(it);
            }
            m[it]++;
        }
        int n=nums.size();
        for(int i=1;i<=n;i++)
        {
            if(m[i]==0)
            {
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};