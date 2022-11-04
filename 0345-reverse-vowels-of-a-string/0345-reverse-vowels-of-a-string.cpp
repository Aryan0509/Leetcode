class Solution {
public:
    
    bool vowel(char x)
    {
        if(x=='a' or x=='e' or x=='i' or x=='o' or x=='u' or x=='A' or x=='E' or x=='I' or x=='O' or x=='U' )
        {
            return true;
        }
        return false;
    }
    
    void reverse(string &s)
    {
        string x="";
        int n=s.length();
        for(int i=n-1;i>=0;i--)
        {
            x+=s[i];
        }
        s=x;
    }
    
    string reverseVowels(string s) {
        string x="";
        for(auto it:s)
        {
            if(vowel(it))
            {
                x+=it;
            }
        }
        reverse(x);
        int n=s.length();
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(vowel(s[i]))
            {
                s[i]=x[k++];    
            }
        }
        return s;
    }
};