class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>arr;
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            if(m[nums[i]]==0)
            {
                arr.push_back(nums[i]);
                    m[nums[i]]++;
            }
        }
                 for(int i=0;i<arr.size();i++)
                 {
                     nums[i]=arr[i];
                 }
                 return arr.size();
    }
};