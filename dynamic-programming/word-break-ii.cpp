class Solution {
public:
    unordered_map<string,vector<string> >m;
    vector<string> wordBreak(string s, vector<string>& wordDict){
        if(m.find(s)!=m.end()) return m[s];
        vector<string> res;
        for(string a: wordDict){
            if(a.compare(s.substr(0,a.size()))==0){
                if(a.size()==s.size()){
                    res.push_back(s);
                }
                else{
                    vector<string> tmp = wordBreak(s.substr(a.size()),wordDict);
                    for(string t: tmp){
                        res.push_back(a + " " + t);
                    }
                }
            }
        }
        m[s] = res;
        return m[s];
    }
};
