class Solution {
public:
    bool isgood(string s)
    {
        if(s=="")
        {
            return 1;
        }
        int n=s.length();
        for(int i=0;i<n-1;i++)
        {
            if(s[i+1]==s[i]-32 or s[i+1]==s[i]+32)
                return false;
        }
        return true; 
    }
    
    string makeGood(string s) {
        if(isgood(s))
            return s;
        while(!isgood(s))
        {
            int n=s.length();
            for(int i=0;i<n-1;i++)
            {
                if(s[i+1]==s[i]-32 or s[i+1]==s[i]+32)
                {
                    s=s.substr(0,i)+s.substr(i+2);
                    break;
                }
            }
        }
        return s;
    }
};
