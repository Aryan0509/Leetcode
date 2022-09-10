class Solution {
public:
    int find(string s)
    {
        sort(s.begin(),s.end());
        // int maxl=INT_MIN;
        int l=1;
        while(s[l]==s[0])
        {
            l++;
        }
        return l;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        unordered_map<string,int>m;
        int nq=queries.size();
        int n=words.size();
        for(int i=0;i<nq;i++)
        {
            m[queries[i]]=find(queries[i]);
        }
        for(auto it:words)
        {
            m[it]=find(it);
        }
        vector<int>ans;
        for(int i=0;i<nq;i++)
        {
            int count=0;
            int c=m[queries[i]];
            for(int j=0;j<n;j++)
            {
                if(c<m[words[j]])
                    count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};