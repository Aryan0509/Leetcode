class Solution {
public:
    bool canConstruct(string ransom, string magazine) {
        unordered_map<char,int>m;
        int n=magazine.length();
        for(int i=0;i<n;i++)
        {
            m[magazine[i]]++;
        }
        n=ransom.length();
        for(int i=0;i<n;i++)
        {
            if(!m[ransom[i]])
                return false;
            m[ransom[i]]--;
        }
        return true;
    }
};