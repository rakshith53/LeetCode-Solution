class Solution {
public:
    vector<vector<int> > res;
    int n;
    void help(vector<int>& ans,vector<int>& candidates,int k,int target){
        if(target==0){
            res.push_back(ans);
            return;
        }
        for(int i=k;i<n;i++){
            if(target-candidates[i]>=0 && (i==k || candidates[i]!=candidates[i-1])){
                ans.push_back(candidates[i]);
                help(ans,candidates,i+1,target-candidates[i]);
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> ans;
        help(ans,candidates,0,target);
        return res;
    }
};
