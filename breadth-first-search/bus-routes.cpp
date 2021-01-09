class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int s, int t) {
        if(s==t) return 0;
        unordered_map<int,vector<int> > m;
        unordered_set<int> vis;
        int n = routes.size(),p;
        for(int i=0;i<n;i++){
            p = routes[i].size();
            for(int j=0;j<p;j++){
                m[routes[i][j]].push_back(i);
            }
        }
        queue<int> q;
        q.push(s);
        int len,cur,res=0;
        while(!q.empty()){
            len = q.size();
            while(len--){
                cur = q.front();
                q.pop();
                for(int k:m[cur]){
                    if(vis.find(k)==vis.end()){
                        vis.insert(k);
                        for(int j:routes[k]){
                            if(j==t) return ++res;
                            if(j!=cur)q.push(j);
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
