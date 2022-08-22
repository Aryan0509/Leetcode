class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i=0;
        int count=0;
        while(n>>i!=0)
        {
            // cout<<n;
            if(n>>i&(1)==1)
                count++;
            i++;
            if(i==32)break;
        }
        return count;
    }
};