class Solution {
public:
    int sum(int n)
    {
        int sum=0;
        while(n!=0)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int prod(int n)
    {
        int prod=1;
         while(n!=0)
        {
            prod*=n%10;
            n/=10;
        }
        return prod;
        
    }
    int subtractProductAndSum(int n) {
        return -sum(n)+prod(n);
    }
};