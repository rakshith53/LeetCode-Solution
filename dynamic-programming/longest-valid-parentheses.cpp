class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int left=0,right=0,len =0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                left++;
            else if (s[i]==')')
                right++;
            if(left==right)
                len = max(len,left*2);
            else if(right>left)
                right=0,left=0;
        }
        left = 0,right=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(')
                left++;
            else if(s[i]==')')
                right++;
            if(right==left)
                len = max(len,right*2);
            else if(left>right)
                right=0,left=0;
        }
        return len;
    }
};
