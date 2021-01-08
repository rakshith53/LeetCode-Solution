class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        unordered_set<int> m(a.begin(),a.end());
        vector<int> res;
        for(auto i: b){
            if(m.find(i)!=m.end()){
                m.erase(i);
                res.push_back(i);
            }
        }
        return res;
    }
};
