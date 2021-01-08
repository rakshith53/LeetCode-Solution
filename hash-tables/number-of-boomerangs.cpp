class Solution {
public:
    int numberOfBoomerangs(vector<vector<int> >& points) {
        int num = 0,k = points.size();
        int dp[k][k];
        for (int i = 0; i < k; ++i) {
            dp[i][i] = 0;
            for (int j = i+1; j < k; ++j) {
                dp[i][j] = pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2);
                dp[j][i] = dp[i][j];
            }
        }
        for (int i = 0; i < k; ++i) {
            int n = 1;
            sort(dp[i], dp[i] + k);
            for (int j = 0; j <k - 1; ++j) {
                if (dp[i][j] == dp[i][j+1]) {
                    ++n;
                } else {
                    num  += n*(n-1);
                    n = 1;
                }
            }
            if (n) {
                num  += n*(n-1);
            }
        }
        return num;
    }
};
