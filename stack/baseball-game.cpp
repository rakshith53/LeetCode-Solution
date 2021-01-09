class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int n,sum=0,tmp;
        for(string s: ops){
            if(s[0]=='C'){
                sum-=st.top();
                st.pop();
            }
            else if(s[0]=='D'){
                sum += (st.top()*2);
                st.push(st.top()*2);
            }
            else if(s[0]=='+'){
                 n = st.top();
                 st.pop();
                 sum += (n+st.top());
                 tmp = n+st.top();
                 st.push(n);
                 st.push(tmp);
            }
            else{
                n = stoi(s);
                sum+=n;
                st.push(n);
            } 
            //cout<<sum<<" "<<s<<endl;
        }
        return sum;
    }
};
