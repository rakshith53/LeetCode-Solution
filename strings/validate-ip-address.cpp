class Solution {
public:
    bool isIPv4(string s){
        if(s.size()==0) return false;
        if(count(s.begin(),s.end(),'.')!=3) return false;
        string tmp;
        stringstream a(s);
        int cnt = 0,n,num;
        while(getline(a,tmp,'.')){
            cnt++;
            n = tmp.size();
            if(n==0 || n>3) return false;
            if(n>1 && tmp[0]=='0') return false;
            num = 0;
            for(char c: tmp){
                if(!isdigit(c)) return false;
                num  = num*10 + c-'0';
                if(num > 255) return false;
            }
        }
        return cnt==4;
    }
    
    bool isIPv6(string s){
        if(s.size()==0) return false;
        if(count(s.begin(),s.end(),':')!=7) return false;
        string valid = "abcdefABCDEF1234567890",tmp;
        stringstream a(s);
        int cnt=0,n;
        while(getline(a,tmp,':')){
            cnt++;
            n = tmp.size();
            if(n>4 || n==0) return false;
            for(char c:tmp){
                if(valid.find(c)==string::npos) return false;
            }
        }
        return cnt==8;
    }
    string validIPAddress(string IP) {
        if(isIPv4(IP)) return "IPv4";
        if(isIPv6(IP)) return "IPv6";
        return "Neither";
    }
};
