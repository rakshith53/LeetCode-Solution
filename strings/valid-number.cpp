class Solution {
public:
    bool isNumber(string s) {
        int n = s.size(),i=0;
        while(i<n && s[i]==' ') i++;
        int cnt=0;
        if(s[i]=='-' || s[i]=='+') i++;
        while(i<n && isdigit(s[i])) {
            i++;
            cnt++;
        }
        if(s[i]=='.') i++;
        while(i<n && isdigit(s[i])) {
            i++;
            cnt++;
        }
        if(cnt==0) return false;
        if(s[i]=='e'){
            i++;
            if(s[i]=='+' || s[i]=='-') i++;
            if(!isdigit(s[i])) return false;
            while(i<n && isdigit(s[i])) i++;
        }
        while(i<n && s[i]==' ') i++;
        return (i==n);
    }
};
