class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream a(version1);
        stringstream b(version2);
        
        int n1,n2;
        string num1,num2;
        while(!a.eof() || !b.eof()){
            if(!a.eof()) getline(a,num1,'.');
            else num1 = "0";
            if(!b.eof()) getline(b,num2,'.');
            else num2 = "0";
            n1 = stoi(num1);
            n2 = stoi(num2);
            if(n1==n2) continue;
            return (n1>n2 ? 1 : -1);
        }
        return 0;
    }
};
