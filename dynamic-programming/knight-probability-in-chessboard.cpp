class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        double prob=0;
        int drxn[]={2,1,2,-1,-2,1,-2,-1,2};
        vector<vector<double>> dp(N,vector<double>(N,0));
        dp[r][c]=1;
        while(K--)
        {
            vector<vector<double>> dp2(N,vector<double>(N,0));
            for(int row=0;row<N;row++)
            {
                for(int col=0;col<N;col++)
                { 
                    for(int j=0;j<8;j++)
                    {
                        int x=row+drxn[j];
                        int y=col+drxn[j+1];
                        if(x>=0&&x<N&&y>=0&&y<N)
                        {
                            dp2[x][y]+=(dp[row][col]/8.0);
                        }
                    }   
                }
            }
            dp=dp2;
        }
        for(vector<double> ans:dp)
        {
            for(double x:ans)
                prob+=x;
        }
        return prob;
            
    }
};
