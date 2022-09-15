class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        if(arr.size()%2!=0)
            return {};
        unordered_map<int,int>m;
        for(auto it:arr)
        {
            m[it]++;
        }
        sort(arr.begin(),arr.end());
        vector<int>ans;
        for(auto it:arr)
        {
            if(m[it] and m[2*it])
            {
                m[it]--;
                m[2*it]--;
                ans.push_back(it);
            }
            else if(m[it] and !m[2*it])
            {
                return {};
            }
        }
        return ans;
    }
};