class Solution {
public:
    vector<vector<int> > res;
    int n;
    void help(vector<int>& ans,int k,vector<int>& candidates,int target){
        if(target==0){
            res.push_back(ans);
            return;
        }
        for(int i=k;i<n;i++){
            if(target-candidates[i]>=0){
                ans.push_back(candidates[i]);
                help(ans,i,candidates,target-candidates[i]);
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.rbegin(),candidates.rend());
        n = candidates.size();
        vector<int> ans;
        help(ans,0,candidates,target);
        return res;
    }
};
