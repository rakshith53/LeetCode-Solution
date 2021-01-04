class Solution {
public:
    bool buddyStrings(string a, string b) {
        if(a.size()!=b.size()) return false;
        if(a.compare(b)==0){
            unordered_map<char,int> m;
            for(char c: a){
                m[c]++;
                if(m[c]==2) 
                    return true;
            }
            return false;
        }
        else{
            int first = -1,second = -1,n = a.size();
            for(int i=0;i<n;i++){
                if(a[i]!=b[i]){
                    if(first==-1)
                        first = i;
                    else if(second==-1)
                        second = i;
                    else return false;
                }
            }
            return second!=-1 && a[first]==b[second] && a[second]==b[first];
        }
    }
};
