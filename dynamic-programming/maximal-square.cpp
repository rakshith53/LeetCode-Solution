class Solution {
public:
    int maximalSquare(vector<vector<char>>& a) {
        int n = a.size();
        if(n==0) return 0;
        int m = a[0].size(),len = 0;
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1][j-1]=='1'){
                    dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
                    len = max(len,dp[i][j]);
                }
            }
        }
        return len*len;
    }
};
