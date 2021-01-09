class Solution {
public:
    int n;
    vector<vector<int> > res;
    void dfs(int node,vector<vector<int> >& g,vector<int>& ans){
        if(node == n-1){
            res.push_back(ans);
            return;
        }
        for(int i:g[node]){
            ans.push_back(i);
            dfs(i,g,ans);
            ans.pop_back();
        }
    }
    vector<vector<int> > allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> ans;
        ans.push_back(0);
        dfs(0,graph,ans);
        return res;
    }
};
