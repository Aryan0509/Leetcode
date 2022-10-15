class Solution {
public:
    bool digitCount(string num) {
        map<int,int>m;
        for(auto it:num)
        {
            m[it-'0']++;
        }
        int n=num.length();
        for(int i=0;i<n;i++)
        {
            if(m[i]!=num[i]-'0')
                return false;
        }
        return true;
    }
};