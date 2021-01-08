class Solution {
public:
    vector<vector<bool> >r,c,b;
    bool isValid(int i,int j,char ch){
        if(r[i][ch-'1']) return false;
        r[i][ch-'1'] = true;
        if(c[j][ch-'1']) return false;
        c[j][ch-'1'] = true;
        if(b[3*(i/3)+(j/3)][ch-'1']) return false;
        b[3*(i/3)+(j/3)][ch-'1'] = true;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& a) {
        r.resize(9,vector<bool>(9,false));
        c.resize(9,vector<bool>(9,false));
        b.resize(9,vector<bool>(9,false));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(a[i][j]!='.'){
                    if(!isValid(i,j,a[i][j]))
                        return false;
                }
            }
        }
        return true;
    }
};
