class Solution {
public:
    void generate(int n,int k,int num,int pos,vector<int>&ans)
    {
        if(pos==n)
        {
            ans.push_back(num);
            return;
        }
        
        int rd=num%10;
        if(k==0)
        {
           generate(n,k,num*10+(rd-k),pos+1,ans);
            return;
        }
        if(rd-k>=0)
        {
            generate(n,k,num*10+(rd-k),pos+1,ans);
        }
        if(rd+k<=9)
        {
            generate(n,k,num*10+(rd+k),pos+1,ans);
        }
        return;
        
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        int number;
        for(int i=1;i<=9;i++)
        {
            generate(n,k,i,1,ans);
        }
        return ans;
    }
};