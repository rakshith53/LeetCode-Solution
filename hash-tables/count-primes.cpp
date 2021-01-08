class Solution {
public:
    int countPrimes(int n) {
        vector<bool> dp(n+1,true);
        for(long i=2;i<n;i++){
            if(dp[i]){
                for(long j=i*i;j<n;j+=i){
                    dp[j] = false;
                }
            }
        }
        int cnt = 0;
        for(int i=2;i<n;i++)
            if(dp[i])
                cnt++;
        return cnt;
    }
};
