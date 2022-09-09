class Solution {
public:
    static bool cmp(vector<int>&p1,vector<int>&p2)
    {
        if(p1[0]==p2[0])
        {
            return p1[1]<p2[1];
        }
        return p1[0]>p2[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n=properties.size();
        sort(properties.begin(),properties.end(),cmp);
        int count=0;
        int maxdefence=properties[0][1];
        for(int i=1;i<n;i++)
        {
            if(properties[i][1]<maxdefence)
            {   
                count++;
            }
            maxdefence=max(properties[i][1],maxdefence);
        }
        return count;
    }
};