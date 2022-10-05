class Solution {
public:
    bool checkString(string s) {
        int flag=0;
        for(auto it:s)
        {
            if(it=='a' and flag==1)
                return 0;
            if(it=='b')
                flag=1;
        }
        return 1;
    }
};