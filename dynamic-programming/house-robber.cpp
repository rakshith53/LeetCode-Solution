class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        if(n==0) return 0;
        int pre = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            int temp = max(pre + a[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};
