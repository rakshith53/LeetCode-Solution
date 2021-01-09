class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        if(n==0) return 0;
        vector<vector<int> > dp(3,vector<int>(n,0));
        int t;
        for(int k=1;k<=2;k++){
            t = dp[k-1][0]-a[0];
            for(int i=1;i<n;i++){
                dp[k][i] = max(dp[k][i-1],a[i]+t);
                t = max(t,dp[k-1][i]-a[i]);
            }
        }
        return dp[2][n-1];
    }
};
