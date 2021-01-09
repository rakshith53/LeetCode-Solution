class Solution {
public:
    int maxProduct(vector<int>& a) {
        int cmax = a[0],cmin = a[0],tmp,n=a.size(),ans=a[0];
        for(int i=1;i<n;i++){
            tmp = cmax;
            cmax = max(a[i],max(cmax*a[i],cmin*a[i]));
            cmin = min(a[i],min(tmp*a[i],cmin*a[i]));
            ans = max(cmax,ans);
        }
        return ans;
    }
};
