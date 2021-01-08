class Solution {
public:
    vector<vector<int> > res;
    int n;
    void help(vector<int>& ans,vector<int>& nums,int k){
        res.push_back(ans);
        for(int i=k;i<n;i++){
            if(k==i || nums[i]!=nums[i-1]){
                ans.push_back(nums[i]);
                help(ans,nums,i+1);
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        if(n==0) return res;
        sort(nums.begin(),nums.end());
        vector<int> ans;
        help(ans,nums,0);
        return res;
    }
};
