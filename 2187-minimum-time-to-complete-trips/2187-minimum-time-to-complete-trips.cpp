class Solution {
public:
    
    bool possible(vector<int>& time,long long mid, int totalTrips)
    {
        int count=0;
        for(auto it:time)
        {
            count+=mid/it;
            if(count>=totalTrips)
                return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
        int n=time.size();
        long long e=(long long)(time[0])*(long long)(totalTrips);
        long long s=0;
        long long ans=-1;
        while(s<=e)
        {
            long long mid=(s+e)/2;
            if(possible(time,mid,totalTrips))
            {
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
            
        }
        return ans;
    }
};