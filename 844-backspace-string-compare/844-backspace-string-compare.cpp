class Solution {
public:
    
    string reduce(string s)
    {
        int n=s.length();
        string x="";
        for(int i=0;i<n;i++)
        {   
            if(s[i]=='#')
            {
                int n=x.length();
                if(n>0)
                x=x.substr(0,n-1);
                
            }
            else
            {  
                x+=s[i];
            }       
        }
        return x;
    }
    
    bool backspaceCompare(string s, string t) {
        string s1=reduce(s);
        string s2=reduce(t);
        if(s1==s2)
            return true;
        return false;
        
    }
};