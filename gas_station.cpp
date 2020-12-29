class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0,n=gas.size(),end=n,crt=0,csum=0;
        while(start!=end){
            csum += gas[crt] - cost[crt];
            if(csum>=0){
                start++;
                crt = start;
            }
            else{
                end--;
                crt = end;
            }
        }
        return csum>=0 ? end%n : -1;
    }
};
