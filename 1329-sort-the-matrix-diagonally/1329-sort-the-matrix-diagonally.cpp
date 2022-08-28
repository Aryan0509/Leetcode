class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        int i=0;
        vector<int>v;
        for(int j=0;j<m;j++)
        {
            int r=i;
            int c=j;
            while(r<n and c<m)
            {
                v.push_back(mat[r++][c++]);
            }
            sort(v.begin(),v.end());
            r=i;
            c=j;
            int k=0;
            while(r<n and c<m)
            {
                mat[r++][c++]=v[k++];
            }
            v.clear();
        }
        i=0;
        for(int j=0;j<n;j++)
        {
            int r=j;
            int c=i;
            while(r<n and c<m)
            {
                v.push_back(mat[r++][c++]);
            }
            sort(v.begin(),v.end());
            r=j;
            c=i;
            int k=0;
            while(r<n and c<m)
            {
                mat[r++][c++]=v[k++];
            }
            v.clear();
        }
        return mat;
    }
};