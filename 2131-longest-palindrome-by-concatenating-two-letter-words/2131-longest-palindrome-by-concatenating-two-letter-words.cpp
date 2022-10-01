class Solution {
public:
    string rev(string s)
    {
        string x="";
        int l=s.length()-1;
        while(l>=0)
        {
            x.push_back(s[l--]);
        }
        return x;
    }
    int longestPalindrome(vector<string>& words) {
        map<string,int>m;
        for(auto it:words)
        {
            m[it]++;
        }
        int count=0;
        int flag=0;  
        for(auto it:m)
        {
            if(it.first[0]==it.first[1] and it.second%2!=0)
            {
                flag=1;
                cout<<it.first<<endl;
                m[it.first]--;
                count+=m[it.first]/2;
                m[it.first]=0;
                break;
            }
        }
        // cout<<count;
        for(auto it:m)
        {
            cout<<it.first<<" "<<it.second<<endl;
            if(m[it.first]>0 and m[rev(it.first)]>0)
            {
                if(it.first==rev(it.first))
                    count+=m[it.first]/2;
                else
                count+=min(m[it.first],m[rev(it.first)]);
                // cout<<it.first<<endl;
                m[it.first]=0;
                m[rev(it.first)]=0;
            }
        }
        count=count*2;
        count+=flag;
        return count*2;
        
    }
};