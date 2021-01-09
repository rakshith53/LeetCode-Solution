class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int> >& paths) {
        vector<int> res(N,0);
        vector<vector<int> > G(N);
        for (vector<int>& p : paths) {
            G[p[0] - 1].push_back(p[1] - 1);
            G[p[1] - 1].push_back(p[0] - 1);
        }
        for(int i=0;i<N;i++){
            vector<int> color(5,0);
            for(int j:G[i]){
                color[res[j]] = 1;
            }
            for(int c=4;c>0;c--){
                if(color[c]==0)
                    res[i] = c;
            }
        }
        return res;
    }
};
