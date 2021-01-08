class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> str,ans;
        stringstream s(text);
        string tmp;
        while(getline(s,tmp,' ')){
            str.push_back(tmp);
        }
        int n = str.size();
        for(int i=0;i<n-1;i++){
            if(!first.compare(str[i]) && !second.compare(str[i+1]))
                if(i+2<n)ans.push_back(str[i+2]);
        }
        return ans;
    }
};
