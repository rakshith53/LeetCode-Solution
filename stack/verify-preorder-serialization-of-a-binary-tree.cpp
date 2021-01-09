class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<string> s;
        stringstream p(preorder);
        string tmp;
        while(getline(p,tmp,',')){
            if(tmp.compare("#")!=0)
                s.push(tmp);
            else{
                while(!s.empty() && s.top()=="#"){
                    s.pop();
                    if(s.empty()) return false;
                    s.pop();
                }
                s.push(tmp);
            }
        }
        return s.size()==1 && s.top()=="#";
    }
};
