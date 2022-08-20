class FindSumPairs {
public:
    unordered_map<int,int>m1;
    unordered_map<int,int>m2;
    vector<int>arr1;
    vector<int>arr2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1=nums1;
        arr2=nums2;
        for(auto it:nums1)
            m1[it]++;
        for(auto it:nums2)
            m2[it]++;
    }
    
    void add(int index, int val) {
        m2[arr2[index]]--;
        arr2[index]+=val;
        m2[arr2[index]]++;
    }
    
    int count(int tot) {
        
        int countt=0;
        for(auto it:m1)
        {
            int n1=it.first;
            int c1=it.second;
            int findd=tot-n1;
            if(m2[findd])
            {
                countt+=c1*m2[findd];
            }
        }
        return countt;
        
        
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */