class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n=a.size(),temp1,temp2;
        // for(int i=0;i<n/2;i++)
        // {
        //     for(int j=i;j<n-i-1;j++)
        //     {
        //         temp1=a[i][j];
        //         a[i][j]=a[n-j-1][i];
        //         a[n-j-1][i]=a[n-i-1][n-j-1];
        //         a[n-i-1][n-j-1]=a[j][n-i-1];
        //         a[j][n-i-1]=temp1;
        //     }
        // }
        reverse(a.begin(),a.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(a[i][j],a[j][i]);
            }
        }
    }   
};
