class Solution {
public:
    vector<vector<int> > g;
    vector<bool> vis;
    int n,ans=0;
    int dfs(int node,vector<bool>& hasApple,int my){
        if(vis[node]) return 0;
        vis[node] = true;
        int cost = 0;
        for(int i:g[node]){
            cost += dfs(i,hasApple,2);
        }
        if(cost==0 && !hasApple[node]) return 0;
        return cost+my;
    }
    int minTime(int a, vector<vector<int>>& edges, vector<bool>& hasApple) {
        n = a;
        g.resize(n);
        for(vector<int> i: edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        vis.resize(n,false);
        return dfs(0,hasApple,0);
    }
};
