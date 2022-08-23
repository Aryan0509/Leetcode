class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        int a=target[0];
        int b=target[0];
        for(int i=1;i<n;i++)
        {
            if(target[i]<=a)
            {
                a=target[i];
            }
            else {
                b+=target[i]-a;
                a=target[i];
            }
        }
        return b;
    }
};