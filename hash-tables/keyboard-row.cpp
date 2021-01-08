class Solution {
public:
    bool find(string& s,unordered_set<char>& seen){
        char c;
        for(char a:s) {
            c = a;
            if(c>='A' && c<='Z')
                c+=32;
            if(seen.find(c)==seen.end())
                return false;
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> s1,s2,s3;
        s1 = {'q','w','e','r','t','y','u','i','o','p'};
        s2 = {'a','s','d','f','g','h','j','k','l'};
        s3 = {'z','x','c','v','b','n','m'};
        vector<string> res;
        char c;
        for(string s: words){
            c = s[0];
            if(c>='A' && c<='Z')
                c += 32;
            if(s1.find(c)!=s1.end()){
                //cout<<"s1";
                if(find(s,s1)) res.push_back(s);
            }
            else if(s2.find(c)!=s2.end()){
                //cout<<"s2";
                if(find(s,s2)) res.push_back(s);
            }
            else if(s3.find(c)!=s3.end()){
                //cout<<"s3";
                if(find(s,s3)) res.push_back(s);
            }
        }
        return res;
    }
};
