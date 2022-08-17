class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
                s.push(arr[i]);
            else
            {
                if(arr[i]<0 and s.top()>0)
                {   int flag=0;
                    while(!s.empty() and arr[i]<0 and s.top()>0)
                    {
                        int x=s.top();
                        s.pop();
                        if(abs(x)==abs(arr[i]))
                        {   flag=1;
                            break;
                        }
                        else{
                            if(abs(x)>abs(arr[i]))
                                arr[i]=x;
                            // else s.push(arr[i]);
                        }  
                    }
                    if(!flag)
                    s.push(arr[i]);
                }
                else s.push(arr[i]);
            }
        }
        
        vector<int>ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};