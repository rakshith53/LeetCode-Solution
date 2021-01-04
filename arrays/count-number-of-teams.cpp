class Solution {
public:
    int numTeams(vector<int>& a) {
        int lleft,hleft,lright,hright,n=a.size(),res=0;
        for(int j=0;j<n;j++){
            lleft=hleft=lright=hright=0;
            for(int i=0;i<j;i++){
                if(a[i]<a[j])
                    lleft++;
                if(a[i]>a[j])
                    hleft++;
            }
            for(int k=j+1;k<n;k++){
                if(a[j]<a[k])
                    hright++;
                if(a[j]>a[k])
                    lright++;
            }
            res += (lleft*hright) + (hleft*lright);
        }
        return res;
    }
};
