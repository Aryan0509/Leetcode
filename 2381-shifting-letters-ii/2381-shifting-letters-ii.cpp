class Solution {
public:
    string shiftingLetters(string ss, vector<vector<int>>& shifts) {
        int n=ss.length();
        vector<int>arr(n+1,0);
        for(auto it:shifts)
        {
            int s=it[0];
            int e=it[1];
            bool isinc=it[2];
            if(isinc)
            {
                arr[s]++;
                arr[e+1]--;
            }
            else 
            {
                arr[s]--;
                arr[e+1]++;
            }
        }
        for(int i=1;i<n;i++)
        {
            arr[i]+=arr[i-1];
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                ss[i]='a'+(ss[i]-'a'+arr[i])%26;
            }
            else{
                ss[i]='a'+(26+ss[i]-'a'-abs(arr[i])%26)%26;
            }
        }
        
        return ss;
    }
};