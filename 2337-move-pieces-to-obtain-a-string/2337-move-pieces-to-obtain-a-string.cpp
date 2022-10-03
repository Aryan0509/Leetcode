class Solution {
public:
    string contract(string &s)
    {
        string x="";
        for(auto it:s)
        {
            if(it!='_')
                x.push_back(it);
        }
        return x;
    }
    bool canChange(string start, string target) {
        if(contract(start)!=contract(target))
            return false;
        vector<int>arr1,arr2;
        int n=start.size();
        for(int i=0;i<n;i++)
        {
            if(start[i]=='_')
                continue;
            else if(start[i]=='R')
                arr1.push_back(i+1);
            else arr1.push_back(0-i-1);
        }
        for(int i=0;i<n;i++)
        {
            if(target[i]=='_')
                continue;
            else if(target[i]=='R')
                arr2.push_back(i+1);
            else arr2.push_back(0-i-1);
        }
        int l=arr1.size();
        for(int i=0;i<l;i++)
        {
            
                if(arr2[i]<arr1[i])
                    return false;
            
        }
        return true;
        
    }
};