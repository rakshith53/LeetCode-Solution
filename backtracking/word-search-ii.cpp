class Solution {
public:
    struct TrieNode{
        string word;
        vector<TrieNode*> child;
        TrieNode(){
            word = "";
            child.resize(26,NULL);
        }
    };
    TrieNode* root = new TrieNode();
    vector<string> res;
    int n,m;
    void build(vector<string>& words){
        TrieNode* cur;
        int val;
        for(string s:words){
            cur = root;
            for(char c:s){
                val = c - 'a';
                if(!cur->child[val]) cur->child[val] = new TrieNode();
                cur = cur->child[val];
            }
            cur->word = s;
        }
    }
    void dfs(TrieNode* cur,int i,int j,vector<vector<char> >& board){
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='.' || !cur->child[board[i][j]-'a']) return;
        char c = board[i][j];
        int val = c - 'a';
        cur = cur->child[val];
        if(cur->word.size()>0){
            res.push_back(cur->word);
            cur->word = "";
        }
        board[i][j] = '.';
        dfs(cur,i+1,j,board);
        dfs(cur,i-1,j,board);
        dfs(cur,i,j+1,board);
        dfs(cur,i,j-1,board);
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        n = board.size(),m = board[0].size();
        build(words);
        TrieNode* cur;
        int val;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                val = board[i][j] - 'a';
                if(root->child[val]){
                    cur = root;
                    dfs(cur,i,j,board);
                }
            }
        }
        return res;
    }
};
