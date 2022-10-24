class Solution {
public:
    
    
    bool check(map<char,int>&m,string x)
    {
        map<char,int>mm;
        for(auto it :x)
        {
            if(mm[it]>0)
                return false;
            if(m[it]>0)
            {
                return false;
            }
            mm[it]++;
        }
        return true;
    }
    void rundfs(vector<string>& arr,int s,int n, map<char,int>&m ,int &maxl,string x)
    {
        if(s==n)
        { 
            if(x.length()>maxl)
            {
                maxl=x.length();
            }
            return;
        }
        if(check(m,arr[s]))
        {
            for(auto it:arr[s])
            {
                m[it]++;
            }
            rundfs(arr,s+1,n,m,maxl,x+arr[s]);
            for(auto it:arr[s])
            {
                m[it]--;
            }
        }
        rundfs(arr,s+1,n,m,maxl,x);
    }
    
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        int maxl=0;
        map<char,int>m;
        rundfs(arr,0,n,m,maxl,"");
        return maxl;
    }
};