class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s = "";
        int len = a+b+c;
        int A,B,C;
        A=B=C=0;
        while(len--){
            if((a>=b && a>=c && A!=2) || (B==2 && a>0) || (C==2 && a>0)){
                B=C=0;
                s+='a';
                a--;
                A++;
            }
            else if((b>=a && b>=c && B!=2) || (A==2 && b>0) || (C==2 && b>0)){
                A=C=0;
                s+='b';
                b--;
                B++;
            }
            else if((c>=a && c>=b && C!=2) || (B==2 && c>0) || (A==2 && c>0)){
                B=A=0;
                s+='c';
                c--;
                C++;
            }
        }
        cout<<s;
        return s;
    }
};
