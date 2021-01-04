class Solution {
public:
    int compress(vector<char>& a) {
        int i=0,j=0,n = a.size(),cnt=0;
        if(n<2) return n;
        string tmp;
        while(i<n){
            a[j] = a[i];
            cnt = 0;
            while(i<n && a[j]==a[i])
                i++,cnt++;
            if(cnt==1) j++;
            else{
                tmp = to_string(cnt);
                for(char c: tmp)
                    a[++j] = c;
                j++;
            }
        }
        return j;
    }
};
