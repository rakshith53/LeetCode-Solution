class Solution {
public:
    int n,m;
    void dfs(int i,int j,vector<vector<int> >& a,vector<vector<bool> >& v,int val){
        if(i<0 || i==n || j<0 || j==m || v[i][j] || val > a[i][j]) return;
        v[i][j] = true;
        dfs(i+1,j,a,v,a[i][j]);
        dfs(i-1,j,a,v,a[i][j]);
        dfs(i,j+1,a,v,a[i][j]);
        dfs(i,j-1,a,v,a[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        vector<vector<int> > res;
        n = a.size();
        if(n==0) return res;
        m = a[0].size();
        vector<vector<bool> > pac(n,vector<bool>(m,false));
        vector<vector<bool> > ata(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            dfs(i,0,a,pac,INT_MIN);
            dfs(i,m-1,a,ata,INT_MIN);
        }
        for(int i=0;i<m;i++){
            dfs(0,i,a,pac,INT_MIN);
            dfs(n-1,i,a,ata,INT_MIN);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && ata[i][j]){
                    res.push_back(vector<int>{i,j});
                }
            }
        }
        return res;
    }
};
