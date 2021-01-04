class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& a, int t) {
        vector<vector<int> > res;
        sort(a.begin(),a.end());
        int n = a.size(),l,r,sum,left,right;
        for(int i=0;i<n-3;i++)
        {
            if(i==0 || (a[i]!=a[i-1])){
                for(int j=i+1;j<n-2;j++)
                {
                    if(j==i+1 || a[j]!=a[j-1]){
                        l=j+1;
                        r=n-1;
                        while(l<r){
                            sum = a[l]+a[r]+a[i]+a[j];
                            if(t == sum){
                                res.push_back(vector<int> {a[i],a[j],a[l],a[r]});
                                left = a[l];
                                right = a[r];
                                while(l<r && a[l]==left) l++;
                                while(r>l && a[r]==right) r--;
                            }
                            else if(sum < t)
                                l++;
                            else
                                r--;
                        }
                    }
                    //while(j+1<n && a[j]==a[j+1]) j++;
                }
                //while(i+1<n && a[i]==a[i+1]) i++;
            }
        }
    return res;
    }
};
