class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        priority_queue<int>q;
        for(auto it:m)
            q.push(it.second);
        int count=0;
        int i=0;
        while(count<(n/2))
        {
            count+=q.top();
            q.pop();
            i++;
        }
        return i;
    }
};