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
            if(s[i+1]==s[i])
                return false;
        }
        return true; 
    }
    
    
    string removeDuplicates(string s) {
        stack<char>ss;
        int n=s.length();
        int i=0;
        while(i<n)
        {
            if(ss.empty())
            {
                ss.push(s[i]);
                i++;
            }
            else 
            {
                if(ss.top()==s[i])
                {
                    ss.pop();
                    i++;
                }
                else{
                        ss.push(s[i]);
                        i++;
                }
            }
        }
        s="";
        while(!ss.empty())
        {
            s+=ss.top();
            ss.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};