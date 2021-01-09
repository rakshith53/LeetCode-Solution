class Solution {
public:
    vector<int> parent;
    int findParent(int i){
        return parent[i]==i?i:parent[i]=findParent(parent[i]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        int components = n;
        for(auto &edge: connections){
            int src = findParent(edge[0]);
            int dest = findParent(edge[1]);
            components -= src!=dest;
            if(src!=dest) parent[dest] = src;
        }
        
        return components-1;
    }
};
