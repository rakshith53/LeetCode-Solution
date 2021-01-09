class Solution {
public:
    int n,m;
    void help(int i,vector<vector<int> > &a,vector<bool> &v)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==1 && !v[j])
            {
                v[j] = 1;
                help(j,a,v);
            }
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& a) {
        n = a.size();m = a[0].size();
        vector<bool> v(n,false);
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(!v[i])
            {
                cnt++;
                help(i,a,v);
            }
        }
        return cnt;
    }
};
