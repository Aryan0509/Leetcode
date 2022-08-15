class Solution {
public:
    int strStr(string big, string sm) {
        int x=sm.length();
        int n=big.length();
        for(int i=0;i<=n-x;i++)
        {
            if(big.substr(i,x)==sm)
                return i;
        }
        return -1;
    }
};