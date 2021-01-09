class Solution {
public:
    int n,m;
    bool isValid(int i,int j)
    {
        if(i<0 || i==n || j<0 || j==m) 
            return false;
        return true;
    }
    void help(int i,int j,vector<vector<char>>& a)
    {
        if(isValid(i,j) && a[i][j]=='O')
        {
            a[i][j]='*';
            help(i+1,j,a);
            help(i-1,j,a);
            help(i,j+1,a);
            help(i,j-1,a);
        }
    }
    void solve(vector<vector<char>>& a) {
        n = a.size();
        if(n==0) return ;
        m = a[0].size();
        for(int i=0;i<n;i++){
            if(a[i][0]=='O')
                help(i,0,a);
            if(a[i][m-1]=='O')
                help(i,m-1,a);
        }   
        for(int j=0;j<m;j++) {
            if(a[0][j]=='O')
                help(0,j,a);
            if(a[n-1][j]=='O')
                help(n-1,j,a);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='O')
                    a[i][j]='X';
                else if(a[i][j]=='*')
                    a[i][j]='O';
            }
        }
        return;
    }
};
