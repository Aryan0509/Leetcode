class Solution {
public:
    
    void rundfs(vector<vector<int>>& img1, vector<vector<int>>& img2,int n1,int m1,int n2,int m2,int i,int j,int k,int x,int &common, vector<vector<int>>&visited1, vector<vector<int>>&visited2)
        
    {
        if((i<0 or i>=n1) or (k<0 or k>=n2) or (j<0 or j>=m1) or (x<0 or x>=m2))
            return;
        if(visited1[i][j] or visited2[k][x])
            return;
        
        
        visited1[i][j]=1;
        visited2[k][x]=1;
        if(img1[i][j]==1 and img2[k][x]==1)
        {
            common++;
        }
        
         rundfs(img1,img2,n1,m1,n2,m2,i+1,j,k+1,x,common,visited1,visited2);
         rundfs(img1,img2,n1,m1,n2,m2,i-1,j,k-1,x,common,visited1,visited2);
         rundfs(img1,img2,n1,m1,n2,m2,i,j+1,k,x+1,common,visited1,visited2);
         rundfs(img1,img2,n1,m1,n2,m2,i,j-1,k,x-1,common,visited1,visited2);
        
    }
    
    
    int findcommon(vector<vector<int>>& img1, vector<vector<int>>& img2,int n1,int m1,int n2,int m2,int i,int j,int k,int x)
    {
        int common=0;
        vector<vector<int>>visited1(n1,vector<int>(m1,0));
        vector<vector<int>>visited2(n2,vector<int>(m2,0));
        
        rundfs(img1,img2,n1,m1,n2,m2,i,j,k,x,common,visited1,visited2);
        return common;
        
    }
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int maxx=INT_MIN;
        int n1=img1.size();
        int m1=img1[0].size();
        int n2=img2.size();
        int m2=img2[0].size();
        
        
                for(int k=0;k<n2;k++)
                {
                    for(int x=0;x<m2;x++)
                    {
                        maxx=max(maxx,findcommon(img1,img2,n1,m1,n2,m2,0,0,k,x));
                        maxx=max(maxx,findcommon(img1,img2,n1,m1,n2,m2,0,m1-1,k,x));
                        maxx=max(maxx,findcommon(img1,img2,n1,m1,n2,m2,n1-1,0,k,x));
                        maxx=max(maxx,findcommon(img1,img2,n1,m1,n2,m2,n1-1,m1-1,k,x));
                    }
                }

        return maxx;    
    }
};