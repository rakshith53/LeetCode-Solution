class Solution {
public:
    int help(vector<int>& dp){
        stack<int> s;
        int n = dp.size(),i=0,t,ans = 0;
        while(i<n){
            if(s.empty())
                s.push(i++);
            else{
                if(dp[s.top()] < dp[i])
                    s.push(i++);
                else{
                    t = s.top();
                    s.pop();
                    if(s.empty())
                        ans = max(ans,dp[t]*i);
                    else 
                        ans = max(ans,dp[t]*(i-1-s.top()));
                }
            }
        }
        while(!s.empty()){
            t = s.top();
            s.pop();
            if(s.empty())
                ans = max(ans,dp[t]*i);
            else 
                ans = max(ans,dp[t]*(i-1-s.top()));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& a) {
        int n = a.size();
        if(n==0) return 0;
        int m = a[0].size();
        int ans = 0;
        vector<int> dp(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='1') dp[j]++;
                else dp[j] = 0;
            }
            ans = max(ans,help(dp));
        }
        return ans;
    }
};

