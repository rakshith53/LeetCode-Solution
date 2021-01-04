class Solution {
public:
    void get(string& s){
        for(char& c:s)
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') c='*';
    }
    void low(string& tmp,string& s){
        for(char c:s) tmp+=tolower(c);
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> word;
        unordered_map<string,string> ignore;
        unordered_map<string,string> vow;
        string tmp;
        for(string w:wordlist){
            if(word.find(w)==word.end()) word.insert(w);
            tmp = "";
            low(tmp,w);
            //cout<<tmp<<" ";
            if(ignore.find(tmp)==ignore.end()) ignore[tmp] = w;
            get(tmp);
            //cout<<tmp<<" "<<w<<endl;
            if(vow.find(tmp)==vow.end()) vow[tmp] = w;
        }
        int n = queries.size();
        for(int i=0;i<n;i++){
            if(word.find(queries[i])!=word.end()) continue;
            tmp = "";
            low(tmp,queries[i]);
            if(ignore.find(tmp)!=ignore.end()) {
                queries[i] = ignore[tmp];
                continue;
            }
            get(tmp);
            if(vow.find(tmp)!=vow.end()){
                queries[i] = vow[tmp];
                continue;
            }
            queries[i] = "";
        }
        return queries;
    }
};
