class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        for(char c:s)
            m[c]++;
        int ans = 0;
        bool f = false;
        for(auto i:m){
            if(i.second%2==0)
                ans += i.second;
            else{
                ans += i.second-1;
                f = true;
            }
        }
        return f ? ans+1 : ans;
    }
};
