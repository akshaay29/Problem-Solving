class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAng=minutes*6.0;
        double hourAng=30.0 * (hour%12) + 0.5*minutes;
        double diff = abs(hourAng-minAng);
        return min(diff,360-diff);
    }
};