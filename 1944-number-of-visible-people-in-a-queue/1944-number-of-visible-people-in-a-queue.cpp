class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int>ans(n,0);
        stack<int>s;
        s.push(0);
        for(int i=1;i<n;i++)
        {
            while(!s.empty() and heights[s.top()]<heights[i])
            {
                ans[s.top()]++;
                s.pop();
            }
            if(!s.empty())
                ans[s.top()]++;
            s.push(i);
        }
        return ans;
    }
};