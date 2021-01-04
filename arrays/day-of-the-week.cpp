class Solution {
public:
    int months[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> week = {"Wednesday", "Thursday", "Friday", "Saturday","Sunday", "Monday", "Tuesday"};
    bool isLeapYear(int y){
        return ((y%4==0 && y%100!=0) || y%400==0);
    }
    int getday(int day,int month,int year){
        int sum = 0;
		for (int i = 1971; i < year; i++) {
			sum += 365;
			if (isLeapYear(i)) {
				sum++;
			}
		}
		for (int i = 1; i < month; i++) {
			sum += months[i - 1];
			if (i == 2 && isLeapYear(year)) {
				sum++;
			}
		}
		sum += day - 1;
		return sum;
    }
    string dayOfTheWeek(int day, int month, int year) {
        int giv = getday(day,month,year);
        int cur = getday(12,8,2020);
        return week[((giv-cur)%7+7)%7];
    }
};
