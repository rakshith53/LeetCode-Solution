class Solution {
public:
    int coinChange(vector<int>& coins, int k) {
        vector<int> dp(k+1,k+1);
        dp[0] = 0;
        for(int i=1;i<=k;i++){
            for(int c:coins)
                if(c<=i)
                    dp[i] = min(dp[i],dp[i-c]+1);
        }
        return dp[k]==k+1 ? -1 : dp[k];
    }
};
