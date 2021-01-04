class Solution {
public:
    bool isalpha(char c){
        return ((c>='A' && c<='Z') || (c>='a' && c<='z'));
    }
    string reverseOnlyLetters(string s) {
        int l = 0,r = s.size()-1;
        while(l<r){
            if(isalpha(s[l]) && isalpha(s[r])){
                swap(s[l],s[r]);
                l++;
                r--;
            }
            else if(!isalpha(s[l])){
                l++;
            }
            else if(!isalpha(s[r])){
                r--;
            }
        }
        return s;
    }
};
