class Solution {
public:
    unordered_map<string,unordered_map<string,double> > g;
    unordered_set<string> eq;
    double dfs(string a,string b,unordered_set<string>& seen){
        if(a.compare(b)==0) return 1;
        if(g[a].find(b)!=g[a].end()) return g[a][b];
        seen.insert(a);
        for(auto x:g[a]){
            string tmp = x.first;
            if(seen.find(tmp)!=seen.end()) continue;
            double d = dfs(tmp,b,seen);
            if(d>0) return d*g[a][tmp];
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string> >& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for(int i=0;i<n;i++){
            g[equations[i][0]][equations[i][1]] = values[i];
            g[equations[i][1]][equations[i][0]] = 1.0/values[i];
            eq.insert(equations[i][1]);
            eq.insert(equations[i][0]);
        }
        n = queries.size();
        vector<double> res;
        for(int i=0;i<n;i++){
            if(eq.find(queries[i][0])==eq.end() || eq.find(queries[i][1])==eq.end()){
                res.push_back(-1);
                continue;
            }
            unordered_set<string> seen;
            res.push_back(dfs(queries[i][0],queries[i][1],seen));
        }
        return res;
    }
};
