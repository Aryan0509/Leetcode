class Solution {
public:
    long long rev(int x)
    {
        long long rev=0;
        bool isneg=x<0?1:0;
        x=abs(x);
        while(x>0)
        {
            rev=rev*10+x%10;
            x/=10;
        }
        if(isneg)
        {
            rev=0-rev;
        }
        return rev;
    }    
    
    
    
    int reverse(int x) {
        long long ans=rev(x);
            if(abs(ans)>INT_MAX)
                return 0;
        return ans;
    }
};