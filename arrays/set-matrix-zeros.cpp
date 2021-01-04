class Solution {
public:
    int x = (int)'@';
    void setZeroes(vector<vector<int> >& a) {
        int n = a.size(),m = a[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==0){
                    for(int k=0;k<n;k++)
                        if(a[k][j]!=0)
                            a[k][j] = x;
                    for(int k=0;k<m;k++)
                        if(a[i][k]!=0)
                            a[i][k] = x;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==x)
                    a[i][j] = 0;
            }
        }
    }
};
