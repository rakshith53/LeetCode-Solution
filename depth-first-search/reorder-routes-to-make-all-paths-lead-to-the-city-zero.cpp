class Solution {
public:
    vector<vector<int> > a,b;
    vector<int> vis;
    int cnt = 0;
    void dfs(int node){
        // if(vis[node]) return;
        vis[node] = true;
        for(int i:a[node]){
            if(!vis[i]){
                cnt++;
                dfs(i);
            }
        }
        for(int i:b[node]){
            if(!vis[i])
                dfs(i);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        a.resize(n);
        b.resize(n);
        vis.resize(n,false);
        for(vector<int> i:connections){
            a[i[0]].push_back(i[1]);
            b[i[1]].push_back(i[0]);
        }
        dfs(0);
        return cnt;
    }
};
