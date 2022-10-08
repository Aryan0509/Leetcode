class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>sti(n);
        vector<long long>bsti(n);
        sti[0]=nums[0];
        bsti[n-1]=0;
        for(int i=1;i<n;i++)
        {
            sti[i]=nums[i]+sti[i-1];
            bsti[n-i-1]=nums[n-i]+bsti[n-i];
        }
        int c=0;
        for(int i=0;i<n-1;i++)
        {
            if(sti[i]>=bsti[i])
                c++;
        }
        return c;
    }
};