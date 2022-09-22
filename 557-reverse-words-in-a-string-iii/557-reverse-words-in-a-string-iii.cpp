class Solution {
public:
    void reverse(string &s,int i,int j)
    {
        j=j-1;
        while(i<=j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    string reverseWords(string s) {
        int n=s.length();
        int i=0;
        int j=1;
        while(j<n)
        {
            if(s[j]==' ')
            {
                reverse(s,i,j);
                i=j+1;
                j++;
            }
            else j++;
        }
        reverse(s,i,j);
        return s;
        
    }
};