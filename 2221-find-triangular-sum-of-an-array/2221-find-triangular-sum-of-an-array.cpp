class Solution {
public:
    int triangularSum(vector<int>& arr) {
        
        int n=arr.size();
        while(n!=1)
        {
            for(int i=0;i<n-1;i++)
            {
                arr[i]=(arr[i]+arr[i+1])%10;
            }
            n--;
        }
        return arr[0];
        
    }
};