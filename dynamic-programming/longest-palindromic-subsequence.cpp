class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size(),j;
        vector<vector<int> > dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
            dp[i][i] = 1;
        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                j = i+l-1;
                if(s[i]==s[j] && l==2)
                    dp[i][j] = 2;
                else {
                    dp[i][j] = s[i]==s[j] ? dp[i+1][j-1]+2 : max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
