class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        vector<int>arr1(n,0);
        vector<int>arr2(n,0);
        vector<int>arr3(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<garbage[i].length();j++)
            {
                if(garbage[i][j]=='M')
                {
                    arr1[i]++;
                }
                else if(garbage[i][j]=='P')
                {
                    arr2[i]++;
                }
                else arr3[i]++;
            }
        }
        int mfinal=0,gfinal=0,pfinal=0;
        for(int i=n-1;i>=0;i--)
        {
            if(arr1[i]!=0)
            {
                mfinal=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(arr2[i]!=0)
            {
                pfinal=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(arr3[i]!=0)
            {
                gfinal=i;
                break;
            }
        }
        int total=0;
        
        total+=arr1[0];
        for(int i=1;i<=mfinal;i++)
        {
            total+=travel[i-1];
            total+=arr1[i];
        }
        total+=arr2[0];
        for(int i=1;i<=pfinal;i++)
        {
            total+=travel[i-1];
            total+=arr2[i];
        }
        total+=arr3[0];
        for(int i=1;i<=gfinal;i++)
        {
            total+=travel[i-1];
            total+=arr3[i];
        }
        return total;
        
    }
};