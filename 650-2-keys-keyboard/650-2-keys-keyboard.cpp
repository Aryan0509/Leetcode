class Solution {
public:
    int findnum(int initialcopy,int n,int m)
    {
        if(initialcopy==n)
            return 1;
        if(n==0)
            return 0;
        if(initialcopy>n)
            return INT_MAX/2;
        return min(1+findnum(initialcopy,n-initialcopy,m+initialcopy),2+findnum(m+initialcopy,n-initialcopy,m+initialcopy));
    }
    int minSteps(int n) {
        if(n==1)
            return 0;
        return 1+findnum(1,n-1,1);
    }
};