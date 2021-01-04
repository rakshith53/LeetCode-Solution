class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v(26,0);
        for(char i: magazine)
            v[i-'a']++;
        for(char j: ransomNote)
            if(--v[j-'a']<0) return false;
        return true;
    }
};
