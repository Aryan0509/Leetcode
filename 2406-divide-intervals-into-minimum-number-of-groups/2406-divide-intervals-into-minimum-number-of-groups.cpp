class Solution {
public:
    struct compare{
        bool operator()(vector<vector<int>> &v1,vector<vector<int>> &v2)
        {
            return v1[v1.size()-1][1]>v2[v2.size()-1][1];
        }
    };
    static bool cmp(vector<int>&v1,vector<int>&v2)
    {
        if(v1[0]==v2[0])
            return v1[1]<v2[1];
        return v1[0]<v2[0];
    }
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        priority_queue<vector<vector<int>>,vector<vector<vector<int>>>,compare>pq;
        for(auto it:intervals)
        {
            if(pq.size()==0)
            {
                vector<vector<int>>xx;
                xx.push_back(it);
                pq.push(xx);
                continue;
            }
            vector<vector<int>>x=pq.top();
            if(x[x.size()-1][1]<it[0])
            {
                x.push_back(it);
                pq.pop();
                pq.push(x);
            }
            else
            {
                vector<vector<int>>xx;
                xx.push_back(it);
                pq.push(xx);
            }
        }
        return pq.size();
    }
};