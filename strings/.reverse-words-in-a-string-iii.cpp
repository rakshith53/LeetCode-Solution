class Solution {
public:
    string reverseWords(string s) {
        if(s.size()==0) return s;
        reverse(s.begin(),s.end());
        stringstream a(s);
        string tmp;
        stack<string> st;
        while(a >> tmp)
            st.push(tmp);
        tmp = "";
        while(!st.empty()){
            tmp +=st.top()+" ";
            st.pop();
        }
        tmp.pop_back();
        return tmp;
    }
};
