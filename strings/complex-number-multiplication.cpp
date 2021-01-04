class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ar=0,br=0,ac=0,bc=0;
        int idx=0;
        int i=0;
        while(a[i]!='+'){
            i++;
        }
        ar = stoi(a.substr(idx,i));
        i++;
        idx=i;
        while(a[i]!='i'){
            i++;
        }
        ac = stoi(a.substr(idx,i));
        idx=0;
        i=0;
        while(b[i]!='+'){
            i++;
        }
        br = stoi(b.substr(idx,i));
        i++;
        idx=i;
        while(b[i]!='i'){
            i++;
        }
        bc = stoi(b.substr(idx,i));
        int sr=0,sc=0;
        sr = ar*br - ac*bc;
        sc = ar*bc + br*ac;
        string s="";
        s= s+ to_string(sr)+"+"+to_string(sc)+"i";
        return s;
    }
};
