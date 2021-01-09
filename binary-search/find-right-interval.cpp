class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& v) {
        map<int,int> m;
        int n = v.size();
        vector<int> res(n,0);
        for(int i=0;i<n;i++)
            m[v[i][0]] = i;
        for(int i=0;i<n;i++){
            auto it = m.lower_bound(v[i][1]);
            if(it == m.end()) res[i] = -1;
            else res[i] = it->second;
        }
        return res;
    }
};
