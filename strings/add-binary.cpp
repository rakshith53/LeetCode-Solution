class Solution {
public:
    string addBinary(string a, string b) {
        int  i=a.size()-1,j=b.size()-1,c=0;
        string res = "";
        while(i>=0 || j>=0 || c){
            c += i>=0 ? a[i--]-'0' : 0;
            c += j>=0 ? b[j--]-'0' : 0;
            res = char(c%2 + '0') + res;
            c/=2;
        }
        return res;
    }
};
