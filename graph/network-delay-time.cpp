class Solution {
public:
    typedef pair<int,int> pii;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        unordered_map<int,vector<pii> > g;
        int u,v,w,z = times.size();
        for(int i=0;i<z;i++){
            u = times[i][0];
            v = times[i][1];
            w = times[i][2];
            g[u].push_back({v,w});
        }
        priority_queue<pii,vector<pii>,greater<pii> > q;
        dist[k] = 0;
        q.push({0,k});
        pii cur;
        while(!q.empty()){
            cur = q.top();
            q.pop();
            u = cur.second;
            for(pii i:g[u]){
                w = i.second;
                v = i.first;
                if(dist[v] > dist[u]+w){
                    dist[v] = dist[u]+w;
                    q.push({dist[v],v});
                }
            }
        }
        int ans = *max_element(dist.begin()+1,dist.end());
        return ans==INT_MAX ? -1 : ans;
    }
};
