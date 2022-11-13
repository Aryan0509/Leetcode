class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        vector<string>v;
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                continue;
            }
            else{
                string x="";
                x+=s[i];
                int j=i+1;
                while(j<n and s[j]!=' ')
                {
                    x+=s[j];
                    j++;
                }
                v.push_back(x);
                i=j-1;
            }
        }
        reverse(v.begin(),v.end());
        string x="";
        for(auto it:v)
        {
            x+=it;
            x+=" ";
        }
        x.pop_back();
        return x;
    }
};