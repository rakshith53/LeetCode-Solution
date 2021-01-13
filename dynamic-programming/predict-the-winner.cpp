class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size()% 2 == 0) return true;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int x,y,z;
        for(int l=0;l<n;l++){
            for(int i=0,j=l;j<n;j++,i++){
                x = i+2 <= j ? dp[i+2][j] : 0;
                y = i+1 <= j-1 ? dp[i+1][j-1] : 0;
                z = i <= j-2 ? dp[i][j-2] : 0;
                dp[i][j] = max(nums[i]+min(x,y),nums[j]+min(z,y));
            }
        }
        return 2*dp[0][n-1] >= accumulate(nums.begin(), nums.end(), 0);
    }
};
