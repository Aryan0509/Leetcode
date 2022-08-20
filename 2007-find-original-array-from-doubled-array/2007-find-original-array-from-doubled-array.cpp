class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int>m;int n=changed.size();
        if(n%2!=0) return {};
        if(changed.size()==1 and changed[0]==0)return {};
        for(auto it:changed)
        {
            m[it]++;
        }
        
        sort(changed.begin(),changed.end());
        vector<int>v;
        for(auto it:changed)
        {
            if(m[it]==0)continue;
            if(m[it]>0 and m[2*it]>0)
            {
                m[it]--;
                m[2*it]--;
                // cout<<it<<" ";
                v.push_back(it);
            }
            else if(m[it]>0 and m[2*it]==0)
            {
                return {};
            }
        }
        return v;
    }
};