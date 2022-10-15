class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalsum) {
        if(finalsum%2!=0)
            return {};
        long long i=2;
        long long sum=0;
        vector<long long>v;
        while(sum+i<=finalsum)
        {
            sum+=i;
            v.push_back(i);
            i+=2;
        }
        if(sum==finalsum)
            return v;
        if(sum<finalsum)
        {
            sum-=v[v.size()-1];
            v.pop_back();
            v.push_back(finalsum-sum);
        }
        return v;
        
        
    }
};