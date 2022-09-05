class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int>visited(26,0);
        for(auto it:allowed)
        {
            visited[it-'a']=1;
        }
        int count=0;
        for(auto it:words)
        {
            int flag=1;
            
            for(auto x:it)
            {
                if(visited[x-'a']==0)
                    
                {
                    flag=0;
                    break;
                }
                
            }
            if(flag)
                count++;
            
        }
        return count;
    }
};