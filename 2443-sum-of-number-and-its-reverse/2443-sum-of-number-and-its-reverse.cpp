class Solution {
public:
    int reverse(int n)
    {
        
       
        int x=0;
        while(n>0)
        {
            int a=n%10;
            x=x*10+a;
            n=n/10;
        }
        return x;
    }
    bool sumOfNumberAndReverse(int num) {
        if(!num)return 1;
        for(int i=1;i<=num;i++)
        {
            if(i+reverse(i)==num)
                return true;
        }
        return false;
    }
};