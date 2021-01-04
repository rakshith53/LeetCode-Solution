class Solution {
public:
    vector<vector<int> > diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int,vector<int> > cnt;
        vector<int> tmp;
        int n = mat.size(),m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cnt[i-j].push_back(mat[i][j]);
            }
        }
        for(auto& c:cnt)
            sort(c.second.begin(),c.second.end());
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                mat[i][j] = cnt[i-j].back();
                cnt[i-j].pop_back();
            }
        }
        return mat;
    }
};
