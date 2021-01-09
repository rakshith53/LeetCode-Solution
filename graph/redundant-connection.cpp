class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(1005,0);
        for(int i=0;i<1005;i++) parent[i] = i;
        int u,v;
        for(auto edge:edges){
            u = edge[0];
            v = edge[1];
            while(u != parent[u]) u = parent[u];
            while(v != parent[v]) v = parent[v];
            if(u == v) return edge;
            parent[v] = u;
        }
        return vector<int>{};
    }
};
