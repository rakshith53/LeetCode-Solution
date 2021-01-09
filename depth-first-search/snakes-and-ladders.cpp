class Solution {
public:
    pair<int,int> get(int k,int n){
        int r = n - ((k-1)/n) -1;
        int c = (k-1)%n;
        if(r%2 == n%2) return {r,n-c-1};
        return {r,c};
    }
    int snakesAndLadders(vector<vector<int> >& board) {
        int n = board.size();
        vector<vector<bool> > vis(n,(vector<bool>(n,false)));
        queue<int> q;
        q.push(1);
        vis[n-1][0] = true;
        int cur,steps = 0,k;
        while(!q.empty()){
            k = q.size();
            while(k--){
                cur = q.front();
                q.pop();
                if(cur == n*n) return steps;
                for(int i=1;i<=6;i++){
                    if(cur+i > n*n) continue;
                    pair<int,int> c = get(cur+i,n);
                    if(vis[c.first][c.second]) continue;
                    vis[c.first][c.second] = true;
                    if(board[c.first][c.second]!=-1) q.push(board[c.first][c.second]);
                    else q.push(cur+i);
                }
            }
            steps++;
        }
        return -1;
    }
};
