class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
       int tt=0;
        tt+=(ax2-ax1)*(ay2-ay1);
        tt+=(bx2-bx1)*(by2-by1);
        
        if(ax2<=bx1 or bx2<=ax1 or ay1>=by2 or ay2<=by1)
            return tt;
        
        int re=min(ax2,bx2);
        int le=max(bx1,ax1);
        int e1=re-le;
        int te=min(ay2,by2);
        int lle=max(ay1,by1);
        int e2=te-lle;
        return tt-e1*e2;
        
    }
};