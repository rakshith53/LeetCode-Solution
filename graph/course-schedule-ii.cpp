class Solution {
public:
    vector<int> res;
    bool dfs(int node,vector<vector<int> >& g,vector<bool>& visiting,vector<bool>& visited){
        if(visiting[node]) return true;
        if(visited[node]) return false;
        visiting[node] = true;
        for(int i:g[node])
            if(dfs(i,g,visiting,visited))
                return true;
        res.push_back(node);
        visiting[node] = false;
        visited[node] = true;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > g(numCourses);
        for(vector<int>& p:prerequisites){
            g[p[1]].push_back(p[0]);
        }
        vector<bool> visiting(numCourses,false);
        vector<bool> visited(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(dfs(i,g,visiting,visited))
                return vector<int> {};
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
