class Solution {
public:
    int maximum69Number (int num) {
        vector<int>arr;
        while(num!=0)
        {
            arr.push_back(num%10);
            num=num/10;
        }
        reverse(arr.begin(),arr.end());
        int c=0;
        int x=0;
        for(auto it:arr)
        {
            if(it==6 and c==0)
            {   x=x*10+9;
                c++;
            }
            else x=x*10+it;
        }
        return x;
    }
};