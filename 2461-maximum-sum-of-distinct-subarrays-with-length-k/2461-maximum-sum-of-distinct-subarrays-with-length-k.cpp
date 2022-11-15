class Solution {
public:
    void print(deque<int>q)
    {
        while(!q.empty())
        {
            cout<<q.back()<<" ";
            q.pop_back();
        }
    }
    
    long long maximumSubarraySum(vector<int>& nums, int k) {
        deque<int>q;
        int n=nums.size();
        int i=0;
        long long sum=0;
        long long msum=0;
        map<int,int>m;
        while(i<n)
        {
            if(m[nums[i]]==0)
            {
                q.push_front(nums[i]);
                m[nums[i]]++;
                sum+=nums[i];
            }
            else{
                while(!q.empty() and m[nums[i]]!=0)
                {
                    m[q.back()]--;
                    sum-=q.back();
                    // cout<<1;
                    q.pop_back();
                }
                q.push_front(nums[i]);
                sum+=nums[i];
                m[nums[i]]++;
            }
            if(q.size()==k)
            {
                msum=max(sum,msum);
                // print(q);
                cout<<endl;
                m[q.back()]--;
                sum-=q.back();
                q.pop_back();
            }
            i++;
            
        }
        return msum;
        return 0;
    }
};