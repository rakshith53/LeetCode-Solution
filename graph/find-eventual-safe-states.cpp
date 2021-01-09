class Solution {
public:
    int n;
    bool dfs(vector<vector<int>>& graph,vector<int>& visited,int a){
        if(visited[a]!=0) return visited[a]==1;
        visited[a] = 2;
        for(int i:graph[a])
            if(!dfs(graph,visited,i)) return false;
        visited[a] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> visited(graph.size(),0);    
        vector<int> res;
        for(int i=0;i<n;i++){
            if(dfs(graph,visited,i)) res.push_back(i);
        }
        return res;
    }
};
