class Solution {
public:
    int find(vector<int>& parent,int x){
        if(parent[x] == x) return x;
        return find(parent,parent[x]);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int u,v,p;
        vector<int> parent(n+1,0),edge1,edge2;
        for(auto &edge: edges){
            if(parent[edge[1]] == 0)
                parent[edge[1]] = edge[0];
            else {
                edge1 = {parent[edge[1]],edge[1]};
                edge2 = edge;
                edge[1] = 0;
            }
        }
        for(int i=1;i<=n;i++) parent[i] = i;
        for(auto edge:edges){
            if(edge[1]==0) continue;
            u = edge[0];
            v = edge[1];
            p = find(parent,u);
            if(p == v){
                if(edge1.empty()) return edge;
                return edge1;
            }
            parent[v] = p;
        }
        return edge2;
    }
};
