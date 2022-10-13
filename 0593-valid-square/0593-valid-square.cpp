class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int>sides;
        vector<pair<int,int>>p;
        p.push_back({p1[0],p1[1]});
        p.push_back({p2[0],p2[1]});
        p.push_back({p3[0],p3[1]});
        p.push_back({p4[0],p4[1]});
        
        for(int i=0;i<3;i++)
        {
            for(int j=i+1;j<4;j++)
            {
                int x1,x2,y1,y2;
                x1=p[i].first;
                x2=p[j].first;
                y1=p[i].second;
                y2=p[j].second;
                sides.push_back((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
                
            }
            
        }
        sort(sides.begin(),sides.end());
        // for(auto it:sides)
        //     cout<<it<<endl;
        
         if(sides[0]==sides[1] and sides[1]==sides[2] and sides[2]==sides[3] and sides[4]==sides[5] and sides[3]==sides[4])
            return false;
        if(sides[0]==sides[1] and sides[1]==sides[2] and sides[2]==sides[3] and sides[4]==sides[5])
            return true;
        return false;
    }
};