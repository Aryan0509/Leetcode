class Solution {
public:
    int partitionString(string s) {
        map<char,int>m;
        int count=1;
        for(auto it:s)
        {
            if(m[it]>0)
            {
                m.clear();
                m[it]++;
                count++;
            }
            else m[it]++;
        }
        return count;
    }
};