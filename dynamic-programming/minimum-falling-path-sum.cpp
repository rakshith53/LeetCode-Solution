class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size(),m = a.size();
        int k,b,c;
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                k = j-1>=0 ? a[i-1][j-1] : INT_MAX;
                b = a[i-1][j];
                c = j+1<m ? a[i-1][j+1] : INT_MAX ;
                a[i][j] += min(c,min(k,b));
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++)
            ans = min(ans,a[n-1][i]);
        return ans;
    }
};
