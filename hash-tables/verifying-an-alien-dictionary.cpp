class Solution {
public:
    unordered_map<char,int> m;
    bool check(string& a,string& b){
        int i=0,j=0,x=a.size(),y=b.size();
        while(i<x && j<y){
            if(m[a[i]] > m[b[j]]) return true;
            else if(m[a[i]] < m[b[j]]) return false;
            i++,j++;
        }
        if(j==y) return true;
        return false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int i=0;
        for(char c:order)
            m[c] = i++;
        int n = words.size();
        for(int i=0;i<n-1;i++){
            if(check(words[i],words[i+1]))
                return false;
        }
        return true;
    }
};
