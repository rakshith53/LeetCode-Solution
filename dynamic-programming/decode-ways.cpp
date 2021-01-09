class Solution {
public:
    int numDecodings(string a) {
        int n = a.size();
        if(n==0 || a[0]=='0') return 0;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            if(a[i-1]>'0')
                dp[i] += dp[i-1];
            if(a[i-2]=='1' || (a[i-2]=='2' && a[i-1]<'7'))
                dp[i] += dp[i-2];
        }
        return dp[n];
    }
};
