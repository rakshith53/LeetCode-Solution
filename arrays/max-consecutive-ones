class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int n = a.size(),ans=0,cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                cnt++;
                ans = max(cnt,ans);
            }
            else cnt=0;
        }
        return ans;
    }
};
