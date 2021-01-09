class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if (sum < s || (s + sum) & 1) return 0;
        s = (s+sum)>>1;
        int n = nums.size();
        // vector<int> dp(s+1,0);
        // dp[0] = 1;
        // for (int n : nums)
        //     for (int i = s; i >= n; i--)
        //         dp[i] += dp[i - n];
        // return dp[s];
        vector<vector<int> > dp(n+1,vector<int>(s+1,0));
        for(int i=0;i<=n;i++) dp[i][0] = 1;
        for(int i=1;i<=n;i++) dp[i][0] = nums[i-1]==0 ? 2*dp[i-1][0] : dp[i-1][0];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=s;j++){
                dp[i][j] = dp[i-1][j];
                if(nums[i-1]<=j)
                    dp[i][j] += dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][s];
    }
};
