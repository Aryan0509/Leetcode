class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int>m;
        for(auto it:nums)
        {
            m[it]++;
        }
        for(auto it:m)
        {
            int x=m[it.first];
            if(x==0)continue;
            for(int i=0;i<k;i++)
            {
                if(m[it.first+i]<x)
                    return false;
                m[it.first+i]-=x;
            }
        }
        return true;
    }
};