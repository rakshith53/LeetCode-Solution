class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        if(a.size()==0) return vector<int>{};
        int n = a.size(),max=1;
        sort(a.begin(),a.end());
        vector<int> dp(n+1,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]%a[j]==0 && dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    if(max < dp[i]) max = dp[i];
                }
            }
        }
        int prev = -1;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==max && (prev%a[i]==0 || prev==-1)){
                ans.push_back(a[i]);
                max--;
                prev = a[i];
            }
        }
        return ans;
    }
};
