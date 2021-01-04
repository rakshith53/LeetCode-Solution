class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& w, string p) {
        vector<string> res;
        int len = p.size(),n;
        for(string s : w){
            if(len!=s.size()) continue;
            bool f = true;
            map<char,char> m;
            vector<bool> seen(26,false);
            for(int i=0;i<len;i++){
                if(m.find(p[i])==m.end())
                    m[p[i]] = s[i];
                else if(m[p[i]]!=s[i]){
                    //cout<<m[p[i]]<<" "<<s[i]<<endl;
                    f = false;
                    break;
                }
            }
            if(!f) continue;
            for(auto it=m.begin();it!=m.end();it++){
                if(seen[it->second-'a']) {
                    //cout<<it->first<<" "<<it->second;
                    f = false;
                    break;
                }
                seen[it->second-'a'] = true;
            }
            if(f) res.push_back(s);
        }
        return res;
    }
};
