class Solution {
public:
    int scoreOfParentheses(string s) {
        int bal=0,n = s.size(),ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')bal++;
            else {
                bal--;
                if(s[i-1]=='(') ans += 1<<bal;
            }
        }
        return ans;
    }
};
