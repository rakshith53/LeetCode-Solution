static int _ = [] { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();
class Solution {
public:
    bool bfs(vector<vector<int> >& g,int node,vector<int>& color){
        queue<int> q;
        q.push(node);
        color[node] = 1;
        int cur;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            for(int ele: g[cur]){
                if(color[ele]==color[cur])
                    return false;
                if(color[ele]==-1){
                    color[ele] = 1-color[cur];
                    q.push(ele);
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int> >& d) {
        vector<vector<int> > g(n);
        int m = d.size();
        for(int i=0;i<m;i++){
            g[d[i][0]-1].push_back(d[i][1]-1);
            g[d[i][1]-1].push_back(d[i][0]-1);
        }
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1)
                if(!bfs(g,i,color))
                    return false;
        }
        return true;
    }
};
