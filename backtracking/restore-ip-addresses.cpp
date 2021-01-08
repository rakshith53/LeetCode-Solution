class Solution {
public:
    vector<string> res;
    void dfs(string& s,int pos,int cnt,string cur){
        if(pos==s.size() && cnt==4){
            cur.pop_back();
            res.push_back(cur);
            return;
        }
        if(pos>=s.size() || cnt>=4) return;
        for(int i=1;i<=3;i++){
            string tmp = s.substr(pos,i);
            if(i>1 && tmp[0]=='0') return;
            int val = stoi(tmp);
            if(val>=0 && val<=255)
                dfs(s,pos+i,cnt+1,cur+tmp+'.');
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string tmp;
        dfs(s,0,0,"");
        return res;
    }
};
