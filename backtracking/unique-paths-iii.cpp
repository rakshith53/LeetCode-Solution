class Solution {
public:
    int ans=0,starti,startj,endi,endj,n,m;
    bool isValid(int x,int y){
        if(x<0 || x==n || y<0 || y==m) return true;
        return false;
    }
    void dfs(int x,int y,vector<vector<int> >& a,int cnt){
        if(isValid(x,y) || a[x][y]<0 || cnt<1) return;
        if(x==endi && y==endj && cnt==1){
            ans++;
            return;
        }
        a[x][y] = -2;
        dfs(x+1,y,a,cnt-1);
        dfs(x-1,y,a,cnt-1);
        dfs(x,y+1,a,cnt-1);
        dfs(x,y-1,a,cnt-1);
        a[x][y] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& a) {
        n = a.size();
        if(n==0) return 0;
        m = a[0].size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                    starti = i,startj = j;
                if(a[i][j]==2)
                    endi = i,endj = j;
                if(a[i][j]!=-1)
                    cnt++;
            }
        }
        dfs(starti,startj,a,cnt);
        return ans;
    }
};
