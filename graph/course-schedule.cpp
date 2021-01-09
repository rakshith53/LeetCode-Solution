class Solution {
public:
    bool dfs(vector<vector<int> >& g,vector<bool>& visiting,vector<bool>& visited,int n){
        if(visiting[n]) return true;
        if(visited[n]) return false;
        visiting[n] = true;
        for(int i:g[n])
            if(dfs(g,visiting,visited,i))
                return true;
        visiting[n] = false;
        visited[n] = true;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int> > g(n);
        vector<bool> visiting(n,false);
        vector<bool> visited(n,false);
        for(auto &p:prerequisites)
            g[p[1]].push_back(p[0]);
        for(int i=0;i<n;i++)
            if(dfs(g,visiting,visited,i)) 
                return false;
        return true;
    }
};
