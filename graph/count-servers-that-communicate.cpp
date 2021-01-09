class Solution {
public:
    int countServers(vector<vector<int>>& g) {
        int n = g.size(),m = g[0].size();
        vector<int> row(n,0),col(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j])
                    row[i]++,col[j]++;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1 && (col[j]>1 || row[i]>1))
                    cnt++;
            }
        }
        return cnt;
    }
};
