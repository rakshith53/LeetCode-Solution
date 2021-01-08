class Solution {
public:
    vector<vector<int> > res;
    void help(int p,int n,int k,vector<int>& cur){
        if(k==0){
            res.push_back(cur);
            return;
        }
        for(int i=p;i<=n;i++){
            cur.push_back(i);
            help(i+1,n,k-1,cur);
            cur.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<int> cur;
        help(1,n,k,cur);
        return res;
    }
};
