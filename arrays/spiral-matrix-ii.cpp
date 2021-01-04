class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int left=0,top=0,right=n-1,bottom=n-1,cnt=1,i;
        vector<vector<int> > a(n,vector<int> (n,0));
        while(left<=right && top<=bottom)
        {
            for(i=left;i<=right;i++)
                a[top][i] = cnt++;
            for(i=top+1;i<=bottom;i++)
                a[i][right] = cnt++;
            if(left<right && top<bottom)
            {
                for(i=right-1;i>left;i--)
                    a[bottom][i] = cnt++;
                for(i=bottom;i>top;i--)
                    a[i][left] = cnt++;
            }
            top++;
            left++;
            right--;
            bottom--;
        }
        return a;
    }
};
