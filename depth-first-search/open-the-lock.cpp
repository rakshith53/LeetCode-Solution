class Solution {
public:
    vector<string> get(string cur){
        string tmp;
        vector<string> res;
        for(int i=0;i<4;i++){
            tmp = cur;
            tmp[i] = (cur[i]-'0'+1)%10 + '0';
            res.push_back(tmp);
            tmp[i] = (cur[i]-'0'-1+10)%10 + '0';
            res.push_back(tmp);
        }
        return res;
    }
    
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> s(deadends.begin(),deadends.end());
        unordered_set<string> vis;
        queue<string> q;
        string k = "0000",cur;
        if(s.find(k)!=s.end() || s.find(target)!=s.end()) return -1;
        q.push(k);
        vis.insert(cur);
        int l=0,res=0;
        while(!q.empty()){
            l = q.size();
            while(l--){
                cur = q.front();
                q.pop();
                vector<string> next = get(cur);
                for(string i:next){
                    if(target.compare(i)==0) return ++res;
                    if(vis.find(i)!=vis.end()) continue;
                    if(s.find(i)==s.end()){
                        q.push(i);
                        vis.insert(i);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
