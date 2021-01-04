class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n =a.size();
        vector<int> ans(n,0);
        ans[0] = 1;
        for(int i=1;i<n;i++){
            ans[i] = ans[i-1] * a[i-1];
        }
        int r = 1;
        for(int i=n-1;i>=0;i--){
            ans[i] = ans[i]*r;
            r*=a[i];
        }
        return ans;
    }
};
