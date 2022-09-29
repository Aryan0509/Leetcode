class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>ans;
        for(int i=1;i<=n;i++)
        {
            string x="";
            if(i%3==0 and i%5==0)
                x="FizzBuzz";
            else if(i%3==0)
                x="Fizz";
            else if(i%5==0)
                x="Buzz";
            else x=to_string(i);
            ans.push_back(x);
        }
        return ans;
    }
};