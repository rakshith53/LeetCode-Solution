class Solution {
public:
    vector<vector<int> > merge(vector<vector<int>>& a) {
        vector<vector<int> > ans;
        int n = a.size();
        if(n==0) return ans;
        sort(a.begin(),a.end(),[](vector<int>& a,vector<int>& b){
            return a[0] < b[0];
        });
        int pre_s = a[0][0],pre_e = a[0][1],cur_s,cur_e;
        for(int i=1;i<n;i++)
        {
            cur_s = a[i][0];
            cur_e = a[i][1];
            if(pre_e >= cur_s){
                pre_e = max(cur_e,pre_e);
            }
            else{
                ans.push_back(vector<int>{pre_s,pre_e});
                pre_s = cur_s;
                pre_e = cur_e;
            }
        }
        ans.push_back(vector<int>{pre_s,pre_e});
        return ans;
    }
};
