class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& word) {
        unordered_map<string,int> count;
        for(int i=0;i<word.size();i++) count[word[i]]++;
        int n = s.size(),num = word.size();
        if(n==0 || num == 0) return vector<int> {};
        int m = word[0].size(),j;
        vector<int> ind;
        string str = "";
        for(int i=0;i<n-(num*m)+1;i++){
            unordered_map<string,int> z;
            for(j=0;j<num;j++){
                str = s.substr(i+(j*m),m);
                if(count.find(str)!=count.end()){
                    z[str]++;
                    if(z[str] > count[str]) break;
                }
                else break;
            }
            if(j==num) ind.push_back(i);
        }
        return ind;
    }
};
