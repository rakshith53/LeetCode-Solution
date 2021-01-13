class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]>a[j]){
                    if(dp[j]>=dp[i]){
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[j]+1 == dp[i])
                        cnt[i] += cnt[j];
                }
            }
        }
        int mx=0,ans=0;
        for(int i=0;i<n;i++){
            if(mx<dp[i]){
                mx = dp[i];
            }
        }
        for(int i=0;i<n;i++)
            ans += dp[i]==mx ? cnt[i] : 0;
        return ans;
    }
};
