class Solution {
public:
    vector<vector<int> > res;
    void dfs(int ind,int k,int n,vector<int>& cur){
        if(n==0 && k==0){
            res.push_back(cur);
            return;
        }
        for(int i=ind;i<=9;i++){
            if(n-i<0) return;
            cur.push_back(i);
            dfs(i+1,k-1,n-i,cur);
            cur.pop_back();
        }
    }
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<int> cur;
        dfs(1,k,n,cur);
        return res;
    }
};
