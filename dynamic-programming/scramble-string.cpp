class Solution {
public:
    unordered_map<string,bool> m;
    bool dfs(string s1,string s2,unordered_map<string,bool>& m){
        int len = s1.size();
        bool res = false;
        if(len==0) return true;
        else if(len==1) return !s1.compare(s2);
        else {
            if(m.find(s1+s2)!=m.end())
                return m[s1+s2];
            if(!s1.compare(s2)){
                res = true;
            }
            else
            {
                for(int i=1;i<len && !res;i++){
                    res |= dfs(s1.substr(0,i),s2.substr(0,i),m) && dfs(s1.substr(i,len-i),s2.substr(i,len-i),m);
                    res |= dfs(s1.substr(0,i),s2.substr(len-i,i),m) && dfs(s1.substr(i,len-i),s2.substr(0,len-i),m);
                }
            }
        }
        return m[s1+s2] = res;
    }
    bool isScramble(string s1, string s2) {
        return(dfs(s1,s2,m));
    }
};
