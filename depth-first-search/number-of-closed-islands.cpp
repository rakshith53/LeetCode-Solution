class Solution {
public:
    bool flag = true;
    int n,m;
    void dfs(int i,int j,vector<vector<int> >& g){
        if(i<0 || i==n || j<0 || j==m){
            flag = false;
            return;
        }
        if(g[i][j]==1 || g[i][j]==2) return;
        g[i][j] = 2;
        dfs(i+1,j,g);
        dfs(i-1,j,g);
        dfs(i,j+1,g);
        dfs(i,j-1,g);
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    flag = true;
                    dfs(i,j,grid);
                    ans += flag ? 1 : 0;
                }
            }
        }
        return ans;
    }
};
