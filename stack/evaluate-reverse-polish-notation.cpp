class Solution {
public:
    int evalRPN(vector<string>& s) {
        int n = s.size(),a,b,val;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(!s[i].compare("+"))
            {
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                st.push(a+b);
            }
            else if(!s[i].compare("-"))
            {
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                st.push(b-a);
            }
            else if(!s[i].compare("*"))
            {
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                st.push(a*b);
            }
            else if(!s[i].compare("/"))
            {
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                st.push(b/a);
            }
            else
            {
                val = stoi(s[i]);
                st.push(val);
            }
        }
        return st.top();
    }
};
