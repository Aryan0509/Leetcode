class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>>ans;
        vector<int>v;
        int i=0;
        int j=1;
        int n=s.length();
        while(j<n)
        {
            while(s[j]==s[i])
            {
                j++;
            }
            if(j-i>=3)
            {
                v.push_back(i);
                v.push_back(j-1);
                ans.push_back(v);
                v.clear();
            }
            i=j;
            j++;
        }
         if(j-i>=3)
            {
                v.push_back(i);
                v.push_back(j-1);
                ans.push_back(v);
                v.clear();
            }
        
        return ans;
    }
};