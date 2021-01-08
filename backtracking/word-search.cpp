class Solution {
public:
    int n,m;
    bool dfs(int i,int j,int ind,string& s,vector<vector<char> >& a){
        if(ind==s.size()) return true;
        if(i<0 || i>=n || j<0 || j>=m || a[i][j]!=s[ind]) return false;
        char t = a[i][j];
        a[i][j] = '.';
        if(dfs(i+1,j,ind+1,s,a) || dfs(i-1,j,ind+1,s,a) || dfs(i,j+1,ind+1,s,a) || dfs(i,j-1,ind+1,s,a))
            return true;
        a[i][j] = t;
        return false;
    }
    bool exist(vector<vector<char> >& board, string word) {
        n = board.size(),m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,0,word,board))
                        return true;
                }
            }
        }
        return false;
    }
};
