class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int> > g(n);
        for(auto i:edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        vector<int> indeg(n,0);
        queue<int> q;
        for(int i=0;i<n;i++){
            indeg[i] = g[i].size();
            if(indeg[i]<=1)q.push(i);
        }
        int k,cur;
        while(n>2){
            k = q.size();
            n-=k;
            while(k--){
                cur = q.front();
                q.pop();
                for(int i:g[cur]){
                    indeg[i]--;
                    if(indeg[i]==1)
                        q.push(i);
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
