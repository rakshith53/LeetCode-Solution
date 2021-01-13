class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(),m = s2.size();
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1]+(int)s1[i-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        long ans=0,k = 2*dp[n][m];
        for(char c: s1) ans+=(int)c;
        for(char c: s2) ans+=(int)c;
        return ans-k;
    }
};
