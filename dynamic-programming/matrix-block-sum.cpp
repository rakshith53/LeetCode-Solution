class Solution {
public:
    int n,m;
    int get(int i,int j,vector<vector<int> >& ans){
        if(i<0||j<0) return 0;
        if(i>=n) i = n-1;
        if(j>=m) j = m-1;
        return ans[i][j];
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& a, int k) {
        n = a.size();
        m = a[0].size();
        vector<vector<int> > ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = a[i][j]+get(i-1,j,ans)+get(i,j-1,ans)-get(i-1,j-1,ans);
            }
        }
        vector<vector<int> > sum(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum[i][j] = get(i+k,j+k,ans)-get(i+k,j-k-1,ans)-get(i-k-1,j+k,ans)+get(i-k-1,j-k-1,ans);
            }
        }
        return sum;
    }
};
