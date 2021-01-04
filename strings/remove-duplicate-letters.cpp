class Solution {
public:
    string removeDuplicateLetters(string a) {
        vector<int> cnt(26,0);
        vector<bool> vis(26,false);
        stack<char> s;
        for(char c:a) cnt[c-'a']++;
        for(char c:a) {
            cnt[c-'a']--;
            if(vis[c-'a']) continue;
            while(!s.empty() && c<s.top() && cnt[s.top()-'a']>0){
                vis[s.top()-'a'] = false;
                s.pop();
            }
            s.push(c);
            vis[c-'a'] = true;
        }
        string ans;
        while(!s.empty()){
            ans = s.top() + ans;
            s.pop();
        }
        return ans;
    }
};
