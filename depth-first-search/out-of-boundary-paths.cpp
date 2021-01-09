class Solution {
public:
    int findPaths(int n, int m, int N, int a, int b) {
        if(N<=0) return 0;
        vector<vector<int> > dp(n,vector<int>(m,0));
        vector<int> row = {1,-1,0,0};
        vector<int> col = {0,0,1,-1};
        dp[a][b] = 1;
        int res=0,x,y;
        for(int k=0;k<N;k++){
            vector<vector<int> > temp(n,vector<int>(m,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(dp[i][j]) {
                        for(int l=0;l<4;l++){
                            x = i + row[l];
                            y = j + col[l];
                            if(x<0 || x>=n || y<0 || y>=m) res = (res + dp[i][j])%1000000007;
                            else temp[x][y] = (temp[x][y] + dp[i][j]) % 1000000007;
                        }
                    }
                }
            }
            dp = temp;
        }
        return res;
    }
};
