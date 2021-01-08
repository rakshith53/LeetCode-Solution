class Solution {
public:
    string m[10];
    vector<string> res;
    void help(int ind,string s,string cur){
        if(ind == s.size()){
            res.push_back(cur);
            return;
        }
        string tmp = m[s[ind]-'0'];
        int n = tmp.size();
        for(int i=0;i<n;i++){
            cur += tmp[i];
            help(ind+1,s,cur);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return res;
        m[0] = "0";
        m[1] = "1";
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        string tmp = "";
        help(0,digits,tmp);
        return res;
    }
};
