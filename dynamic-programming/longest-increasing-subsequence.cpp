class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        if(n==0) return 0;
        vector<int> dp(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[i]>a[j])
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        int res = INT_MIN;
        for(int i=0;i<n;i++)
        {
            res = max(res,dp[i]);
        }
        return res;
    }
};
