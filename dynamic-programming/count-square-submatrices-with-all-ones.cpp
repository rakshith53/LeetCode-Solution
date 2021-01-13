class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        //vector<vector<int>> row,cols;
        int r = a.size(),c = a[0].size();
        int res = 0;
        for(int i = 0;i<r;i++) {
            for(int j = 0;j<c;j++) {
                if(a[i][j] && i && j)
                a[i][j] += min(a[i-1][j-1],min(a[i][j-1],a[i-1][j]));
                res += a[i][j];
            }
        }
        return res;
    }
};
