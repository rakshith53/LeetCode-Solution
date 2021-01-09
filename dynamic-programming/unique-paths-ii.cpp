class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        if(a[0][0]==1) return 0;
        a[0][0] = 1;
        int n = a.size(),m = a[0].size();
        for(int i=1;i<n;i++)
            a[i][0] = a[i][0] == 1 ? 0 : a[i-1][0];
        for(int j=1;j<m;j++)
            a[0][j] = a[0][j] == 1 ? 0 : a[0][j-1];
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                a[i][j] = a[i][j] == 0 ? a[i-1][j]+a[i][j-1] : 0;
            }
        }
        return a[n-1][m-1];
    }
};
