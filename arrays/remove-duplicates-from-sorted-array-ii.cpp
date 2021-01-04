class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        if (a.size() == 0) return 0;
        int  k=2,j=0;
        for(int i :a){
            if(j<k || i>a[j-k])
                a[j++] = i;
        }
    return j;
    }
};
