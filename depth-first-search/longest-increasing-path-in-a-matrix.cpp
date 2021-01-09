class Solution {
public:
    int n,m;
    int dfs(int i,int j,vector<vector<int> >& dp,vector<vector<int>>& a,int val){
        if(i<0 || i==n || j<0 || j==m || a[i][j]<=val) return 0;
        if(dp[i][j]) return dp[i][j];
        int l = dfs(i+1,j,dp,a,a[i][j]);
        int r = dfs(i-1,j,dp,a,a[i][j]);
        int u = dfs(i,j+1,dp,a,a[i][j]);
        int d = dfs(i,j-1,dp,a,a[i][j]);
        dp[i][j] = max(max(l,r),max(u,d))+1;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        if(n==0) return 0;
        m = matrix[0].size();
        vector<vector<int> > dp(n,vector<int>(m,0));
        int cnt = 0,ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!dp[i][j]){
                    ans=max(ans,dfs(i,j,dp,matrix,INT_MIN));
                }
            }
        }
        return ans;
    }
};
