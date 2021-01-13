class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> s(days.begin(),days.end());
        int end = days.back();
        vector<int> dp(end+1);
        for(int i=1;i<=end;i++){
            if(s.find(i)==s.end()) dp[i] = dp[i-1];
            else dp[i] = min(dp[i-1]+costs[0],min(dp[max(0,i-7)]+costs[1],dp[max(0,i-30)]+costs[2]));
        }
        return dp[end];
    }
};
