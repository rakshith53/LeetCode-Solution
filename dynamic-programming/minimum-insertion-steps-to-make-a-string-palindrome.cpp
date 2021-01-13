class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int> > dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++) dp[i][i] = 1;
        for(int l=2;l<=n;l++){
            for(int i=0,j;i<n-l+1;i++){
                j = i+l-1;
                if(s[i]==s[j] && l==2) dp[i][j] = 2;
                else if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return n - dp[0][n-1];
    }
};
