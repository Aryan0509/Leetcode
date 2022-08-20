class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int,long long>m;
        long long days=0;
        int n=tasks.size();
        int i=0;
        while(i<n)
        {
            if(m[tasks[i]]<=days)
            {
                m[tasks[i]]=days+space+1;
                i++;
                days++;
                continue;
            }
            else{
                days=m[tasks[i]];
                m[tasks[i]]=days+space+1;
                i++;
                days++;
                
            }
            
        }
        return days;
    }
};