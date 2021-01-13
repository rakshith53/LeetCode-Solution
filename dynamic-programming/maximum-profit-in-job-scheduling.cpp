class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int> > d(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            d[i][0] = endTime[i];
            d[i][1] = startTime[i];
            d[i][2] = profit[i];
        }
        sort(d.begin(),d.end());
        vector<int> dp(n,0);
        dp[0] = d[0][2];
        for(int i=1;i<n;i++){
            dp[i] = max(dp[i-1],d[i][2]);
            for(int j=i-1;j>=0;j--){
                if(d[i][1]>=d[j][0]){
                    dp[i] = max(dp[i],dp[j]+d[i][2]);
                    break;
                }
            }
        }
        int ans = *max_element(dp.begin(),dp.end());
        return ans;
    }
};
