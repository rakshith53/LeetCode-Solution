class Solution {
public:
    vector<int> plusOne(vector<int>& a) {
        int n = a.size(),c=1;
        int i = n-1;
        while(i>=0 && a[i]+c>9){
            a[i] = 0;
            c = 1;
            i--;
        }
        if(i==-1 && c==1)
            a.insert(a.begin(),1);
        else
            a[i]++;
        return a;
    }
};
