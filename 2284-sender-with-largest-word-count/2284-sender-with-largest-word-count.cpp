class Solution {
public:
    
    static bool cmp(pair<string,int>p1,pair<string,int>p2)
    {
        if(p1.second==p2.second)
            return p1.first>p2.first;
        return p1.second>p2.second;
    }
    
    int count(string &s)
    {
        int c=0;
        for(auto it:s)
        {
            if(it==' ')
                c++;
                
        }
        
        return c+1;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int>m;
        int n=messages.size();
        for(int i=0;i<n;i++)
        {
            m[senders[i]]+=count(messages[i]);
        }
        vector<pair<string,int>>p;
        for(auto it:m)
        {
            p.push_back({it.first,it.second});
        }
        sort(p.begin(),p.end(),cmp);
        return p[0].first;
    }
};