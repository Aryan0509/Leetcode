class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char,vector<int>>m;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            m[s[i]].push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            int d=m[ch][1]-m[ch][0]-1;
            if(d!=distance[ch-'a'])
                return false;
        }
        return true;
    }
};