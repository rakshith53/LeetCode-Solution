class Solution {
public:
    vector<vector<string> > res;
    bool isValid(int r,int c,vector<string>& a,int n){
        for(int i=0;i<r;i++)
            if(a[i][c]=='Q')
                return false;
        for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--)
            if(a[i][j]=='Q')
                return false;
        for(int i=r-1,j=c+1;i>=0 && j<n;i--,j++)
            if(a[i][j]=='Q')
                return false;
        return true;
    }
    void help(vector<string>& a,int r,int n){
        if(r==n){
            res.push_back(a);
            return;
        }
        for(int c=0;c<n;c++){
            if(isValid(r,c,a,n)){
                a[r][c] = 'Q';
                help(a,r+1,n);
                a[r][c] = '.';
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<string> a(n,string(n,'.'));
        help(a,0,n);
        return res;
    }
};
