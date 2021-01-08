class Solution {
public:
    vector<vector<int> > res;
    int n;
    void dfs(vector<int>& a,vector<int> &ans,vector<bool>& v){
        if(ans.size()==n){
            res.push_back(ans);
            raeturn;
        }
        for(int i=0;i<n;i++){
            if(!v[i]){
                if(i>0 && a[i]==a[i-1] && !v[i-1]) continue;
                v[i] = true;
                ans.push_back(a[i]);
                dfs(a,ans,v);
                ans.pop_back();
                v[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        vector<int> ans;
        vector<bool> v(n,false);
        sort(nums.begin(),nums.end());
        dfs(nums,ans,v);
        return res;
    }
};
