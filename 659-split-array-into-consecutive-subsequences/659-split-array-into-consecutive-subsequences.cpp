class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int>count;
        map<int,int>prev;
        for(auto it:nums)
            count[it]++;
        
        for(auto i:nums)
        {
            if(count[i]==0)continue;
            if(prev[i-1]>0)
            {
                prev[i-1]--;
                count[i]--;
                prev[i]++;
            }
            else if(count[i+1] and count[i+2])
            {
                count[i+2]--;
                count[i+1]--;
                count[i]--;
                prev[i+2]++;
            }
            else{
                
                return false;}
        }
        return true;
        
    }
};