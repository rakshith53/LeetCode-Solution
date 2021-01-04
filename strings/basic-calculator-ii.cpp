class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n = s.size();
        char sign = '+';
        long val = 0,tmp;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                val = val*10 + s[i]-'0';
            }
            if(!isspace(s[i]) && !isdigit(s[i]) || i==s.size()-1){
                if(sign=='+')
                    st.push(val);
                else if(sign=='-')
                    st.push(-val);
                else if(sign=='*'){
                    val = st.top()*val;
                    st.pop();
                    st.push(val);
                }
                else if(sign=='/'){
                    val = st.top()/val;
                    st.pop();
                    st.push(val);
                }
                sign = s[i];
                val = 0;
            }
        }
        val = 0;
        while(!st.empty()){
            val += st.top();
            st.pop();
        }
        return val;
    }
};
