class Solution {
public:
    vector<vector<bool> >row,col,box;
    void fill(int r,int c,vector<vector<char> >& a,char ch){
        a[r][c] = ch;
        row[r][ch-'1'] = col[c][ch-'1'] = box[3*(r/3)+(c/3)][ch-'1'] = true;
    }
    void unfill(int r,int c,vector<vector<char> >& a,char ch){
        a[r][c] = '.';
        row[r][ch-'1'] = col[c][ch-'1'] = box[3*(r/3)+(c/3)][ch-'1'] = false;
    }
    bool isValid(int i,int j,char c){
        return !(row[i][c-'1'] || col[j][c-'1'] || box[3*(i/3)+(j/3)][c-'1']);
    }
    bool dfs(int i,int j,vector<vector<char> >& a){
        if(i==9) return true;
        if(j==9) return dfs(i+1,0,a);
        if(a[i][j]!='.') return dfs(i,j+1,a);
        for(char c='1';c<='9';c++){
            if(isValid(i,j,c)){
                fill(i,j,a,c);
                if(dfs(i,j+1,a))
                    return true;
                unfill(i,j,a,c);
            }
        }
        return false;
    }
    void make(vector<vector<char> >& a){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(a[i][j]!='.')
                    fill(i,j,a,a[i][j]);
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        row.resize(9,vector<bool>(9,false));
        col.resize(9,vector<bool>(9,false));
        box.resize(9,vector<bool>(9,false));
        make(board);
        dfs(0,0,board);
    }
};
