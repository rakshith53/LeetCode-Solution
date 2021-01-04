class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n = a.size(),csum = 0 ;
        int sum = (n*(n+1))/2;
        for(int i=0;i<n;i++)
            csum += a[i];
        return sum-csum;
    }
};
