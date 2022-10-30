class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum=0;
        int c=0;
        for(auto it:nums)
        {
            if(it%2==0)
            {
                if(it%3==0)
                {
                    sum+=it;
                    c++;
                }
            }
        }
        if(c==0)return 0;
        return sum/c;
    }
};