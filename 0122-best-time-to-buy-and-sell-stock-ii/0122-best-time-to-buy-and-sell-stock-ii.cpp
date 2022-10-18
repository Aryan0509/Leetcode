class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p=0;
        int n=prices.size();
        int i=0,j=0;
        int buy;
        while(j<n)
        {
            buy=prices[i];
            j=i+1;
            while(j<n and prices[j]>prices[i])
            {
                i++;
                j++;
            }
            p+=-buy+prices[i];
            i++;
        }
        return p;
    }
};