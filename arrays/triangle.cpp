class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size(),m;
        for(int i=n-2;i>=0;i--){
            m = a[i].size();
            for(int j=0;j<m;j++){
                a[i][j] += min(a[i+1][j],a[i+1][j+1]);
            }
        }
        return a[0][0];
    }
};
