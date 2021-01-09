class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        if(n==0) return 0;
        int k = a[0],ans =0;
        for(int i=1;i<n;i++) {
            if(a[i]<k) {
                k = a[i];
            }
            ans = max(ans,a[i]-k);
        }
        return ans;
    }
};
