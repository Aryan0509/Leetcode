class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]>mass)
                return false;
            mass+=arr[i];
        }
        return true;
    }
};