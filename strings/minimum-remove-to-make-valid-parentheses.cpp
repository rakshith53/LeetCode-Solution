class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n = s.size(),i=0;
        while(i<n){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                if(st.empty()) s[i] = '*';
                else st.pop();
            }
            i++;
        }
        while(!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        s.erase(remove(s.begin(),s.end(),'*'),s.end());
        return s;
    }
};
