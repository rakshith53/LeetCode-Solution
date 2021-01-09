class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> ind;
        string res="";
        int j,n=s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '(') ind.push_back(res.length());
            else if(s[i]==')'){
                j = ind.back();
                ind.pop_back();
                reverse(res.begin()+j,res.end());
            }
            else res += s[i];
        }
        return res;
    }
};
