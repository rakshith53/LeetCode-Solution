class Solution {
public:
    bool dfs(vector<int>& c,vector<vector<int> >& g,int color,int node){
        if(c[node]!=0) return c[node] == color;
        c[node] = color;
        for(int i:g[node])
            if(!dfs(c,g,-color,i)) return false;
        return true;
    }
    bool isBipartite(vector<vector<int>>& g) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = g.size();
        vector<int> c(n,0);
        for(int i=0;i<n;i++){
            if(c[i]==0 && !dfs(c,g,1,i)) return false;
        }
        return true;
    }
};
