class Solution {
public:
    int n,m;
    vector<int> row = {0,0,1,-1};
    vector<int> col = {1,-1,0,0};
    queue<pair<int,int> > q;
    void dfs(int i,int j,vector<vector<int> >& g){
        if(i<0 || i==n || j<0 || j==m || g[i][j]==2) return;
        if(g[i][j]==0) {
            q.push({i,j});
            return;
        }
        g[i][j] = 2;
        for(int l=0;l<4;l++){
            dfs(i+row[l],j+col[l],g);
        }
    }
    int shortestBridge(vector<vector<int>>& g) {
        bool found = false;
        n = g.size();
        m = g[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]){
                    dfs(i,j,g);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        int size = 0,k=0;
        pair<int,int> p;
        int x,y,a,b;
        found = false;
        while(!q.empty()){
            k = q.size();
            while(k--){
                p = q.front();
                q.pop();
                a = p.first;
                b = p.second;
                for(int i=0;i<4;i++){
                    x = a + row[i];
                    y = b + col[i];
                    if(x>=0 && x<n && y>=0 && y<n){
                        if(g[x][y]==1) {
                            found = true;
                            break;
                        }
                        else if(g[x][y]==0){
                            g[x][y] = 2;
                            q.push({x,y});
                        }
                    }
                }
            }
            size++;
            if(found) break;
        }
        return size;
    }
};
