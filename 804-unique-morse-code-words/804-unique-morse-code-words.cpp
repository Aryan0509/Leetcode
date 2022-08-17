class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>arr={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string>s;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            string x;
            for(auto it:words[i])
            {
                x+=arr[it-'a'];
            }
            s.insert(x);
        }
        return s.size();
    }
};