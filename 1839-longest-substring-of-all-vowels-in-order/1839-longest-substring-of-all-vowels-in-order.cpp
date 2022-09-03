class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n=word.length();
        int s=0;
        while(s<n and word[s]!='a')
            s++;
        int e=s+1;
        map<char,int>m;
        m['a']=1;
        m['e']=2;
        m['i']=3;
        m['o']=4;
        m['u']=5;
        map<char,int>visited;
        visited['a']=0;
        visited['e']=0;
        visited['i']=0;
        visited['o']=0;
        visited['u']=0;
        
        int maxlength=INT_MIN;
        visited[word[s]]=1;
        while(e<n)
        {
            if(m[word[e]]==m[word[e-1]])
            {
                e++;
            }
            else if(m[word[e]]==m[word[e-1]]+1)
            {
                visited[word[e]]=1;
                e++;
            }
            else{
                int flag=1;
                for(auto it:visited)
                {
                    if(it.second==0)
                    {
                        flag=0;
                        break;
                    }
                }
                visited['a']=0;
        visited['e']=0;
        visited['i']=0;
        visited['o']=0;
        visited['u']=0;
                // cout<<visited['u']<<endl;
                if(flag)
                {
                    cout<<s<<' '<<e<<endl;
                    maxlength=max(maxlength,e-s);
                }
                s=e;
                while(s<n and word[s]!='a')
                    s++;
                visited[word[s]]=1;
                e=s+1;
            }
        }
        // cout<<visited['u']<<endl;
        int flag=1;
        for(auto it:visited)
        {
            if(it.second==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            // cout<<s<<' '<<e<<endl;
            maxlength=max(maxlength,e-s);
        }
        return maxlength==INT_MIN?0:maxlength;
    }
};