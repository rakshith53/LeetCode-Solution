class Solution {
public:
    void dfs(vector<string>& ans,unordered_map<string,unordered_set<string> >& graph,string start, unordered_set<string>& visited){
        ans.push_back(start);
        visited.insert(start);
        for(auto s:graph[start])
            if(visited.find(s)==visited.end())
                dfs(ans,graph,s,visited);
    }
    
    
    vector<vector<string> > accountsMerge(vector<vector<string>>& a) {
        unordered_map<string,unordered_set<string> > graph;
        unordered_set<string> visited;
        int n;
        for(vector<string> v: a){
            n = v.size();
            for(int i=2;i<n;i++){
                graph[v[1]].insert(v[i]);
                graph[v[i]].insert(v[1]);
            }
        }
        vector<vector<string> > res;
        vector<string> ans;
        for(vector<string> v: a){
            if(visited.find(v[1])==visited.end()){
                ans.clear();
                dfs(ans,graph,v[1],visited);
                sort(ans.begin(),ans.end());
                ans.insert(ans.begin(),v[0]);
                res.push_back(ans);
            }
        }
        return res;
    }
};
