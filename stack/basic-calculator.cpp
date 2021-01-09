class Solution {
public:
    int calculate(string s) {
        int n = s.size(),i=0,sum=0,csum=0;
        stack<int> st;
        int sign =1;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                csum=0;
                while(i<n && isdigit(s[i])){
                    csum = csum*10 + (s[i]-'0');
                    i++;
                }
                sum += (csum*sign);
                i--;
            }
            else if(s[i]=='+')
                sign = 1;
            else if(s[i]=='-')
                sign = -1;
            else if(s[i]=='(')
            {
                st.push(sum);
                st.push(sign);
                sum=0;sign=1;
            }
            else if(s[i]==')')
            {
                sum *= st.top();
                st.pop();
                sum += st.top();
                st.pop();
            }
        }
        return sum;
    }
};
