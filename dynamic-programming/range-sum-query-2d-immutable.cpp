class NumMatrix {
public:
    vector<vector<int> > dp;
    int n,m;
    int get(int i,int j){
        return i>=0 && j>=0 ? dp[i][j] : 0;
    }
    NumMatrix(vector<vector<int>>& matrix) {
        dp = matrix;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                dp[i][j] = get(i-1,j) + get(i,j-1) - get(i-1,j-1) + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return get(row2,col2) - get(row2,col1-1) - get(row1-1,col2) + get(row1-1,col1-1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
