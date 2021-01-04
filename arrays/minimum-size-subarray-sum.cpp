class Solution {
public:
    int minSubArrayLen(int s, vector<int>& a) {
        int n = a.size(),sum=0,left=0,len=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=a[i];
            while(sum>=s){
                len = min(len,i-left+1);
                sum-=a[left++];
            }
        }
        return len==INT_MAX ? 0 : len;
    }
};
