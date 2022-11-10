class Solution {
public:
    int sumdigits(int x)
    {
        int s=0;
        while(x!=0)
        {
            s+=x%10;
            x/=10;
        }
        return s;
    }
    int countEven(int num) {
        int c=0;
        for(int i=1;i<=num;i++)
        {
            if(sumdigits(i)%2==0)
                c++;
        }
        return c;
    }
};