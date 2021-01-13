class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(),col = matrix[0].size();
        int csum,cnt=0;
        for(int c=0;c<col;c++){
            vector<int> row_sum(row,0);
            for(int j=c;j<col;j++){
                for(int i=0;i<row;i++){
                    row_sum[i] += matrix[i][j];
                }
                unordered_map<int,int> v;
                csum = 0;
                for(int i=0;i<row;i++){
                    v[csum]++;
                    csum += row_sum[i];
                    if(v.find(csum-target)!=v.end()){
                        cnt += v[csum-target];
                    }
                }
            }
        }
        return cnt;
    }
};
