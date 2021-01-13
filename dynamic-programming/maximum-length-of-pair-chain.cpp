class Solution {
public:
    int findLongestChain(vector<vector<int> >& a) {
        if(a.size()==0) return 0;
        if(a.size()==1) return 1;
        int n = a.size();
        sort(a.begin(),a.end());
        vector<int> dp(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[i][0]>a[j][1])
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        int ans=0;
        for(int x: dp)
            ans = max(ans,x);
        return ans;
    }
};
