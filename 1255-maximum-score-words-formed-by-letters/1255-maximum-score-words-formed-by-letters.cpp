class Solution {
public:
    bool ispossible(string s,map<char,int>m)
    {
        for(auto it:s)
        {
            if(m[it]==0)
                return false;
            m[it]--;
        }
        return true;
    }
    void add(map<char,int>&m,string s)
    {
        for(auto it:s)
            m[it]++;
    }
    void remove(map<char,int>&m,string s)
    {
        for(auto it:s)
            m[it]--;
    }
    int findscore(vector<int>&score,string s)
    {
        int cunt=0;
        for(auto it:s)
        {
            cunt+=score[it-'a'];
        }
        return cunt;
    }
    
    void rundfs(vector<string>& words,map<char,int>&m, vector<int>& score,int &maxscore,int currentscore,int s)
    {
        if(s==words.size())
        {
            maxscore=max(maxscore,currentscore);
            return;
        }
        if(ispossible(words[s],m))
        {
            remove(m,words[s]);
            rundfs(words,m,score,maxscore,currentscore+findscore(score,words[s]),s+1);
            add(m,words[s]);
        }
        
        rundfs(words,m,score,maxscore,currentscore,s+1);
        return;
        
    }
    
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char,int>m;
        for(auto it:letters)
            m[it]++;
    
        int maxscore=INT_MIN;
        rundfs(words,m,score,maxscore,0,0);
        return maxscore;
        
        
    }
};