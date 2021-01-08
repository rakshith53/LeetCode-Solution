class Solution {
public:
    vector<string> res;
    int n;
    void dfs(string s,int p){
        res.push_back(s);
        for(int i=p;i<n;i++){
            if(isdigit(s[i])) continue;
            else if(s[i]>='a' && s[i]<='z'){
                s[i] = s[i]-'a'+'A';
                dfs(s,i+1);
                s[i] = s[i]+32;
            }
            else{
                s[i] = s[i]+32;
                dfs(s,i+1);
                s[i] = s[i]-32;
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        n = s.size();
        dfs(s,0);
        return res;
    }
};
