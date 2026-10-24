class Solution {
public:
    int toDayOfYear(string& date) {
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2));
        int day   = stoi(date.substr(3, 2));
        int totalDays = 0;
        for (int i = 0; i < month - 1; i++) totalDays += daysInMonth[i];   
        return totalDays + day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int arrive1=toDayOfYear(arriveAlice);
        int arrive2=toDayOfYear(arriveBob);
        int leave1=toDayOfYear(leaveAlice);
        int leave2=toDayOfYear(leaveBob);
        if(leave1<arrive2 || leave2<arrive1) return 0;
        return min(leave1,leave2)-max(arrive1,arrive2)+1;
    }
};