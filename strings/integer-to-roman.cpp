class Solution {
public:
    string intToRoman(int a) {
        string i[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string x[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string c[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string m[] = {"","M","MM","MMM"};
        return m[a/1000]+c[(a%1000)/100]+x[(a%100)/10]+i[a%10];
    }
};
