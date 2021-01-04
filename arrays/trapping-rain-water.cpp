class Solution {
public:
    int trap(vector<int>& a) {
        int l = 0,r = a.size()-1,ans=0;
        int lm = 0 ,rm = 0;
        while(l<r)
        {
            if(a[l] < a[r]) {
                a[l] >= lm ? (lm = a[l]) : ans += (lm-a[l]);
                l++;
            }
            else {
                a[r] >= rm ? (rm = a[r]) : ans += (rm-a[r]);
                r--;
            }
        }
        return ans;
    }
};
