class Solution {
public:
    struct compare{
        // public:
        int x;
        compare(int n)
        {
            this->x=n;
        }
        bool operator()(int p1,int p2)
        {
            return abs(p1-x)<abs(p2-x);
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        priority_queue<int,vector<int>,compare>q((compare(x)));
        for(int i=0;i<n;i++)
        {
            if(q.size()==k)
            {
                if(abs(q.top()-x)>abs(arr[i]-x))
                {   q.pop();
                q.push(arr[i]);
                }
            }
            else q.push(arr[i]);
        }vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(q.top());
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};