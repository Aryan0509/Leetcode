class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>m;
        unordered_map<char,int>q;
        for(auto it:s)
        {
            m[it]++;
        }
        for(auto it:t)
        {
            if(m[it]>0)
            {
                m[it]--;
            }
            else q[it]++;
        }
        int count=0;
        for(auto it:m)
        {
            count+=it.second;
        }
        for(auto it:q)
        {
            count+=it.second;
        }
        return count;
    }
};