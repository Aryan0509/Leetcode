class Solution {
public:
    void rundfs(int k,int n,int s,int sum,vector<int>&v, vector<vector<int>>&ans)
    {
        if(k==0 and sum==n)
        {
            ans.push_back(v);
            return;
        }
        if(k==0 and sum!=n)
        {
            return;
        }
        if(sum>=n)
            return;
        for(int i=s+1;i<=9;i++)
        {
            v.push_back(i);
            rundfs(k-1,n,i,sum+i,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v;
        rundfs(k,n,0,0,v,ans);
        return ans;
    }
};