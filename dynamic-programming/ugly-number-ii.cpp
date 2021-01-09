class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n,0);
        dp[0] = 1;
        int i2=0,i3=0,i5=0,val;
        int c2=2,c3=3,c5=5;
        for(int i=1;i<n;i++){
            dp[i] = val = min(c2,min(c3,c5));
            while(c2<=val) c2 = 2*dp[i2++];
            while(c3<=val) c3 = 3*dp[i3++];
            while(c5<=val) c5 = 5*dp[i5++];
        }
        return dp[n-1];
    }
};
