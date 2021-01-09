class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        queue<string> q;
        string tmp;
        char ch;
        int cnt = 0,n;
        q.push(beginWord);
        dict.erase(beginWord);
        while(!q.empty()){
            n = q.size();
            while(n--){
                tmp = q.front();
                q.pop();
                if(tmp == endWord) return ++cnt;
                for(char& a:tmp){
                    ch = a;
                    for(char c='a';c<='z';c++){
                        if(ch==c) continue;
                        a = c;
                        if(dict.find(tmp)!=dict.end()){
                            q.push(tmp);
                            dict.erase(tmp);
                        }
                    }
                    a = ch;
                }
            }
            cnt++;
        }
        return 0;
    }
};
