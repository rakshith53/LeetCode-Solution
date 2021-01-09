class Solution {
public:
    int n,m;
    void dfs(int i,int j,vector<vector<int> >& a,int& cnt){
        if(i==n || i<0 || j==m || j<0 || a[i][j]==2 || a[i][j]==0) return;
        a[i][j]=2;
        cnt++;
        dfs(i+1,j,a,cnt);
        dfs(i-1,j,a,cnt);
        dfs(i,j+1,a,cnt);
        dfs(i,j-1,a,cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(),m = grid[0].size();
        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cnt=0;
                dfs(i,j,grid,cnt);
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};
