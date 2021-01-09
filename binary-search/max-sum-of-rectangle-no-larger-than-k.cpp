class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& a, int k) {
        int n = a.size();
        if(n==0) return 0;
        int m = a[0].size();
        int res = INT_MIN;
        for(int l=0;l<m;l++){
            vector<int> tmp(n,0);
            for(int r=l;r<m;r++){
                for(int i=0;i<n;i++){
                    tmp[i] += a[i][r];
                }
                set<int> s;
                s.insert(0);
                int curs=0,curm=INT_MIN;
                for(int b:tmp){
                    curs+=b;
                    auto it = s.lower_bound(curs-k);
                    if(it!=s.end())
                    {
                        curm = max(curm,curs-*it);
                    }
                    s.insert(curs);
                }
                res = max(res,curm);
            }
        }
        return res;
    }
};
