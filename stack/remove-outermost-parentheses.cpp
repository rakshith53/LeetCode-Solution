class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string ans;
        for(char c:s){
            if(c=='(' && cnt++ > 0) ans += c;
            else if(c==')' && cnt-->1 ) ans +=c;
        }
        return ans;
    }
};
