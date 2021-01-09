class Solution {
public:
    typedef pair<int,int> pii;
    int n,m;
    bool isValid(int i,int j){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    int orangesRotting(vector<vector<int> >& grid) {
        n = grid.size(),m = grid[0].size();
        queue<pii> q;
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) cnt++;
            }
        }
        if(cnt==0) return 0;
        int res = 0;
        pii cur;
        vector<int> r = {0,0,1,-1};
        vector<int> c = {1,-1,0,0};
        int x,y,a,b,k;
        while(!q.empty()){
            k = q.size();
            while(k--){
                cur = q.front();
                q.pop();
                x = cur.first;
                y = cur.second;
                for(int i=0;i<4;i++){
                    a = x + r[i];
                    b = y + c[i];
                    if(isValid(a,b) && grid[a][b]==1){
                        q.push({a,b});
                        grid[a][b] = 2;
                        cnt--;
                    }
                }
            }
            res++;
        }
        return cnt==0 ? res-1 : -1;
    }
};
