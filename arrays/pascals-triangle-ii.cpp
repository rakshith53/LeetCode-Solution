class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i=0;i<=n;i++){
            for(int j=i;j>0;j--)
                dp[j] += dp[j-1];
        }
        return dp;
    }
};
