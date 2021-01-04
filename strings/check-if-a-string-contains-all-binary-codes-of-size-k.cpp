class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string,bool> m;
        if(k > s.size()) return false;
        int n = s.size();
        for(int i=0;i<=n-k;i++){
            m[s.substr(i,k)] = true;
            //cout<<s.substr(i,k)<<endl;
        }
        return m.size() == 1<<k ;
    }
};
