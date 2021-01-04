class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> m;
        for(char c: s) m[c]++;
        priority_queue<pair<int,char> > q;
        for(auto it=m.begin();it!=m.end();it++){
            q.push({it->second,it->first});
        }
        pair<int,int> a,b;
        string res = "";
        while(!q.empty()){
            a = q.top(); q.pop();
            res += a.second;
            if(!q.empty()){
                b = q.top();
                q.pop();
                res += b.second;
                if(b.first-1 > 0) q.push({b.first-1,b.second});
            }
            if(a.first-1 > 0) q.push({a.first-1,a.second});
        }
        int n = res.size();
        for(int i=1;i<n;i++) if(res[i]==res[i-1]) return "";
        return res;
    }
};
