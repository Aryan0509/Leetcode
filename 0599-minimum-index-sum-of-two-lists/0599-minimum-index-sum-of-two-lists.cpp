class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,vector<int>>m;
        for(int i=0;i<list1.size();i++)
        {
            m[list1[i]].push_back(i);
        }
        for(int i=0;i<list2.size();i++)
        {
            m[list2[i]].push_back(i);
        }
        int mins=INT_MAX;
        vector<string>ans;
        for(auto it:m)
        {
            if(it.second.size()==2)
            {
                 mins=min(mins,it.second[0]+it.second[1]);
            }
           
        }
                for(auto it:m)
        {
            if(it.second.size()==2)
            {
                 if(it.second[0]+it.second[1]==mins)
                 {
                     ans.push_back(it.first);
                 }
            }
           
        }
        return ans;
        
    }
};