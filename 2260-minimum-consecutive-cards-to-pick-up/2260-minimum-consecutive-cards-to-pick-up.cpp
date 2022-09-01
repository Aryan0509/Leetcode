class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int>m;
        int n=cards.size();
        int minn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(m.find(cards[i])!=m.end())
            {
                if(i-m[cards[i]]<minn)
                {
                    minn=i-m[cards[i]];
                }
            }
            m[cards[i]]=i;
            
        }
        return minn==INT_MAX?-1:minn+1;
    }
};