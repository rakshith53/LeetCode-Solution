class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int start = 0,end = s.size(),cur = end-1;
        end--;
        while(start<=end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                start = 0;
                end = --cur;
            }
        }
        string tmp = s.substr(cur+1);
        reverse(tmp.begin(),tmp.end());
        return tmp+s;
    }
};
