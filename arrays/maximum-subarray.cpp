class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int sum = INT_MIN,csum = 0, n = a.size();
        for(int i=0;i<n;i++){
            csum = max(csum+a[i],a[i]);
            sum = max(csum,sum);
        }
        return sum;
    }
};
