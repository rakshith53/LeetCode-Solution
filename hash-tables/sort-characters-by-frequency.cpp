class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char> > m('z'+1,{0,0});
        for(char c:s) m[(int)c] = {m[(int)c].first+1,c};
        sort(m.rbegin(),m.rend());
        string res = "";
        for(int i=0;i<'z'+1;i++){
            res+=string(m[i].first,m[i].second);
        }
        return res;
    }
};
