class Solution {
public:
    static bool cmp(string &s1,string &s2)
    {
        if(stoi(s1.substr(0,2))==stoi(s2.substr(0,2)))
            return stoi(s1.substr(3,2))<stoi(s2.substr(3,2));
        return stoi(s1.substr(0,2))<stoi(s2.substr(0,2));
    }
    int findMinDifference(vector<string>& tp) {
        sort(tp.begin(),tp.end(),cmp);
        int mind=INT_MAX;
        int n=tp.size();
        for(int i=0;i<n-1;i++)
        {
            int currentmin=0;
            int ch=stoi(tp[i].substr(0,2));
            int th=stoi(tp[i+1].substr(0,2));
            int cm=stoi(tp[i].substr(3,2));
            int tm=stoi(tp[i+1].substr(3,2));
            currentmin+=(th-ch)*60;
            currentmin=currentmin-cm+tm;
            mind=min(mind,currentmin);
        }
        int currentmin=0;
            int ch=stoi(tp[n-1].substr(0,2));
            int th=stoi(tp[0].substr(0,2));
            int cm=stoi(tp[n-1].substr(3,2));
            int tm=stoi(tp[0].substr(3,2));
            currentmin+=(24+(th-ch))*60;
            currentmin=currentmin-cm+tm;
            mind=min(mind,currentmin);
        return mind;
    }
};