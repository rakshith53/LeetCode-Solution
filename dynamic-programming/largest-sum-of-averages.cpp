class Solution {
public:
    double largestSumOfAverages(vector<int>& a, int k) {
        if(a.size()==0 || k==0) return 0;
        int n = a.size();
        vector<double> sum(n,0);
        vector<vector<double> > dp(k+1,vector<double>(n,0));
        sum[0] = a[0];
        for(int i=1;i<n;i++) sum[i] = sum[i-1] + a[i];
        for(int l=1;l<=k;l++){
            for(int i=l-1;i<n;i++){
                if(l==1)
                    dp[l][i] = sum[i]/(i+1);
                else{
                    for(int j=l-2;j<i;j++){
                        dp[l][i] = max(dp[l-1][j] + (sum[i]-sum[j])/(i-j),dp[l][i]);
                    }
                }
            }
        }
        return dp[k][n-1];
    }
};
