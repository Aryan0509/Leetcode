class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int e=*max_element(candies.begin(),candies.end());
        int s=1;
        int ans=-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            int flag=0;
           long long number=0;
            for(auto it:candies)
            {
                number+=it/mid;
                if(number>=k)
                {
                    ans=mid;
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                s=mid+1;
            }
            else e=mid-1;
        }
        return ans==-1?0:ans;
    }
};