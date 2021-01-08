class Solution {
public:
    vector<vector<int> > res;
    int n;
    void help(vector<int>& nums,vector<bool>& v,vector<int>& ans){
        if(ans.size()==nums.size()){
            res.push_back(ans);
            return;
        }
        for(int i=0;i<n;i++){
            if(!v[i]){
                ans.push_back(nums[i]);
                v[i] = true;
                help(nums,v,ans);
                v[i] = false;
                ans.pop_back();
            }
        }
    }
    vector<vector<int> > permute(vector<int>& nums) {
        n = nums.size();
        vector<int> ans;
        vector<bool> v(nums.size(),false);
        help(nums,v,ans);
        return res;
    }
};
