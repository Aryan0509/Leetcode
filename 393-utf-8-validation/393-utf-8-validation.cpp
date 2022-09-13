class Solution {
public:
    
    
    bool check(vector<int>& data,int s,int len)
    {
        s++;
        len--;
        while(len--)
        {
            string x=convert(data[s++]);
            if(x[0]!='1' or x[1]!='0')
                return false;
        }
        return true;
    }
    string convert(int n)
    {
        string x="00000000";
        if(n==0)
            return x;
        cout<<n<<" ";
        int ptr=7;
        while(n!=0)
        {
            x[ptr--]=n%2+'0';
            n=n/2;
        }
        return x;
    }
    int count(vector<int>&data,int s)
    {
        int n=data[s];
        string x=convert(n);
        int i=0;
        int countt=0;
        while(x[i]=='1')
        {
            countt++;
            i++;
        }
        return countt;
    }
    bool validUtf8(vector<int>& data) {
        int n=data.size();
        if(data.size()==1)
        {
           string x=convert(data[0]);
            if(x[0]=='0')
                return true;
            return false;
        }
        int i=0;
        while(i<n)
        {
            int len=count(data,i);
            if(len==0)
            {
                i++;
                
            }
            else if(i+len-1>=n or len>=5)
                return false;
            else if(len==1)
            {
                return false;
            }
            else{
                if(!check(data,i,len))
                {
                    return false;
                }  
                else {
                    i+=len;
                }
            }
        }
        return true;
        
    }
};