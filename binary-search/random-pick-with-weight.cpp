class Solution {
public:
    vector<int> v;
    int sum;
    Solution(vector<int>& w) {
        int n = w.size();
        v.resize(n,0);
        v[0] = w[0];
        for(int i=1;i<n;i++)
            v[i] = (v[i-1]+w[i]);
        sum = v.back();
    }
    
    int pickIndex() {
        int ran = rand()%sum;
        return upper_bound(v.begin(),v.end(),ran)-v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
