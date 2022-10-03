class Solution {
public:
    long long kedane(vector<int>arr)
    {                      
        int n=arr.size();
        long long msum=0;      
        long long csum=0;            
        for(int i=0;i<n;i++) 
        {
            if(csum+arr[i]<0)
            {
                csum=0;
            }
            
            else csum+=arr[i];
              msum=max(csum,msum);
        }
      
        return msum;
    }
    
    long long maxcircular(vector<int>arr,int sum)
    {
        int n=arr.size();
        long long msum=INT_MAX;
        long long csum=0;
        for(int i=0;i<n;i++)
        {
            if(csum+arr[i]>0)
            {
                csum=0;
            }
            else csum+=arr[i];
            msum=min(msum,csum);
        }
          // return sum-msum; 
        long long x=sum-msum;
        // cout<<kedane(arr)<<endl;
        return max(x,kedane(arr));
    }
    long long maxprefix(vector<int>arr)
    {
        long long csum=0;
        long long maxsum=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            csum+=arr[i];
            maxsum=min(csum,maxsum);
        }
        return maxsum;
        
    }
    long long maxsuffix(vector<int>arr)
    {
        long long csum=0;
        long long maxsum=0;
        int n=arr.size();
        for(int i=n-1;i>=0;i--)
        {
            csum+=arr[i];
            maxsum=min(csum,maxsum);
        }
        return maxsum;
        
    }
    long long kConcatenationMaxSum(vector<int>& arr, int k) {
        
        long long sum=0;
        for(auto it:arr)
            sum+=it;
        // cout<<sum<<endl;
        long long mcircular=maxcircular(arr,sum);
        cout<<mcircular<<endl<<kedane(arr);
        long long f=0;
        // int sides=min(sum,maxprefix(arr)+maxsuffix(arr))
        if(k==1)
        {
            return kedane(arr);
            // return max(f,max(mcircular,k*sum-maxprefix(arr)-maxsuffix(arr)))%1000000007;
        }
        return max(f,max(mcircular,k*sum-maxprefix(arr)-maxsuffix(arr)))%1000000007;
    }
    
};