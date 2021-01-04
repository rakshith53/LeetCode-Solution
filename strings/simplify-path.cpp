class Solution {
public:
    string simplifyPath(string path) {
        stringstream s(path);
        string tmp;
        vector<string> st;
        while(getline(s,tmp,'/')){
            if(tmp=="" || tmp==".") continue;
            else if(tmp==".."){
                if(!st.empty())
                    st.pop_back();
            }  
            else st.push_back(tmp);
        }
        string res = "";
        for(string x: st) res += "/"+x;
        return (res.empty() ? "/" : res);
    }
};
