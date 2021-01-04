class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string,int> m;
        int n = names.size(),k;
        for(int i=0;i<n;i++){
            if(m.find(names[i])!=m.end()){
                k = m[names[i]];
                while(m.find(names[i]+'('+(to_string(k))+')')!=m.end()){
                    m[names[i]]++;
                    k++;
                }
                m[names[i]]++;
                names[i] = names[i]+'('+to_string(k)+')';
            }
            m[names[i]]=1;
        }
        return names;
    }
};
