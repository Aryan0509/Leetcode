class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int s=0;
        int e=n-1;
        int score=0;
        while(s<=e)
        {
            if(power<tokens[s] and score==0)
                return score;
            if(power<tokens[s] and score>0)
            {   
                if(s==e)break;
                score--;
                power+=tokens[e];
                e--;
            }
            else
            {
                power-=tokens[s];
                score++;
                s++;
            }
        }
        return score;
    }
};