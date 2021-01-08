class Solution {
public:
    vector<vector<int> > res;
    int n;
    void help(vector<int>& ans,vector<int>& nums,int k){
        res.push_back(ans);
        for(int i=k;i<n;i++){
            ans.push_back(nums[i]);
            help(ans,nums,i+1);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size()==0)  return res;
        n = nums.size();
        vector<int> ans;
        help(ans,nums,0);
        return res;
    }
};
