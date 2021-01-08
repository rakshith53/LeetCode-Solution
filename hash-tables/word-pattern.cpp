class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,int> ci;
        unordered_map<string,int> si;
        stringstream s(str);
        int i=0,n = pattern.size();
        string temp;
        while(getline(s,temp,' ')){
            if(ci[pattern[i]]!=si[temp]) return false;
            ci[pattern[i]] = si[temp] = i+1;
            i++;
        }
        return i==n;
    }
};
