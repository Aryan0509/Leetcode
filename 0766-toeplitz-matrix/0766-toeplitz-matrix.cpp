class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int x=0;x<m;x++)
        {
            int i=1;
            int j=x+1;
            while(i<n and j<m)
            {
                if(matrix[i-1][j-1]!=matrix[i][j])
                    return false;
                i++;
                j++;
            }
        }
        for(int x=0;x<n;x++)
        {
            int i=x+1;
            int j=1;
            while(i<n and j<m)
            {
                if(matrix[i-1][j-1]!=matrix[i][j])
                    return false;
                i++;
                j++;
            }
        }
        
        return true;
    }
};