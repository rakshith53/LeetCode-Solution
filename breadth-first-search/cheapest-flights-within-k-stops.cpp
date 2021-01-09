class Solution {
public:
    typedef pair<int,int> pii;
    int findCheapestPrice(int n, vector<vector<int> >& flights, int src, int dst, int k) {
        unordered_map<int,vector<pii> > g;
        int u,v,w,d;
        for(vector<int>& i:flights){
            u = i[0];
            v = i[1];
            w = i[2];
            g[u].push_back({v,w});
        }
        queue<pii> q;
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        q.push({src,0});
        k++;
        pii cur;
        while(!q.empty()){
            n = q.size();
            if(!k) break;
            while(n--){
                cur = q.front();
                q.pop();
                u = cur.first;
                d = cur.second;
                for(pii x:g[u]){
                    v = x.first;
                    w = x.second;
                    if(dist[v] > d+w){
                        dist[v] = d+w;
                        q.push({v,dist[v]});
                    }
                }
            }
            k--;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
