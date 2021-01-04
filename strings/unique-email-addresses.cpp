class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n,i,cnt=0;
        string tmp="",com="";
        unordered_set<string> m;
        for(string s: emails){
            i = 0;
            n = s.size();
            tmp = "";
            com = "";
            for(int i=0;i<n;i++){
                if(s[i]=='+' || s[i]=='@')
                    break;
                if(s[i]!='.')
                    tmp += s[i];
            }
            i = s.size()-1;
            while(i>=0 && s[i]!='@'){
                com = s[i] + com;
                i--;
            }
            tmp = tmp + "$" + com;
            if(m.find(tmp)==m.end()){
                cnt++;
                m.insert(tmp);
            }
        }
        return cnt;
    }
};
