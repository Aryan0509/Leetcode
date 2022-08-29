class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        nums.assign(s.begin(),s.end());
        priority_queue<int,vector<int>,greater<int>>q;
        for(auto it:nums)
        {
            if(q.size()<3)
            {
                q.push(it);
            }
            else{
                if(it>q.top())
                {
                    q.pop();
                    q.push(it);
                }
            }
        }
        if(q.size()<3)
        {
           return *max_element(nums.begin(),nums.end());
        }
        return q.top();
    }
};