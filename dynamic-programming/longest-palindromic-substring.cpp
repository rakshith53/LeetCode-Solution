class Solution {
public:
    int n;
    int get(int l,int r,string& s){
        if(s.size()==0) return 0;
        while(l>=0 && r<n && s[l]==s[r]){
            l--,r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        if(s.size()==0) return "";
        int len = 0,tmp,start,end;
        n = s.size();
        for(int i=0;i<n;i++){
            len = max(get(i,i,s),get(i,i+1,s));
            if(end-start < len){
                start = i-(len-1)/2;
                end = i+(len/2);
            }
        }
        return s.substr(start,end-start+1);
    }
};
