class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& a) {
        map<int,vector<int> > m;
        int n = a.size(),k;
        for(int i=0;i<n;i++){
            k = a[i].size();
            for(int j=0;j<k;j++){
                m[i+j].push_back(a[i][j]);
            }
        }
        vector<int> res;
        for(auto it=m.begin();it!=m.end();it++){
            for(auto i=it->second.rbegin();i!=it->second.rend();i++){
                res.push_back(*i);
            }
        }
        return res;
    }
};
