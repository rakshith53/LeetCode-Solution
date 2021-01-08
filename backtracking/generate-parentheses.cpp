class Solution {
public:
    vector<string> res;
    void help(int n,string s,int o,int c)
    {
        if(s.size()==n*2)   
        {
            res.push_back(s);
            return ;
        }
        if(o<c) return ;
        if(o<n) help(n,s+'(',o+1,c);
        if(c<n) help(n,s+')',o,c+1);
    }
    vector<string> generateParenthesis(int n) {
        res.clear();
        if(n==0) return res;
        string s = "";
        help(n,s,0,0);
        return res;
    }
};


