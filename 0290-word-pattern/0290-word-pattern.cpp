class Solution {
public:
    
    vector<string> convert(string s)
    {   
        int j,i;
        vector<string>ans;
        i=0;
        j=1;
        int n=s.length();
        while(j<n)
        {
            while(j<n and s[j]!=' ')
            {
                j++;
            }
            int d=j-i;
            ans.push_back(s.substr(i,d));
            i=j+1;
            j++;
        }
        if(i==n-1)
        {
            int d=j-i;
            ans.push_back(s.substr(i,d));
        }
        return ans;
    }
    
    bool wordPattern(string s, string patternn) {
        map<char,string>m;
        int i=0;
        set<string>ss;
        vector<string>pattern=convert(patternn);
        for(auto it:pattern)
            cout<<it<<endl;
        if(s.length()!=pattern.size())
            return false;
        for(auto it:s)
        {   
            if(m.find(it)==m.end())
            {   
                if(ss.find(pattern[i])!=ss.end())
                return false;
                m[it]=pattern[i];
                ss.insert(pattern[i]);
            }
            else if(m[it]!=pattern[i])
                    return false;
            i++;
        }
        // for(auto it:m)
        //     cout<<it.first<<" "<<it.second<<endl;
        
        return true;
    }
    
    
};