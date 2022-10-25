class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string x="";
        string y="";
        for(auto it:word1)
        {
            x+=it;
        }
        for(auto it:word2)
        {
            y+=it;
        }
        return x==y;
    }
};