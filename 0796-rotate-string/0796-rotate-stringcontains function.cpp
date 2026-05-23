class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size()<s.size() || goal.size()>s.size()) return false;
        string ss=s+s;
        return ss.contains(goal);
    }
};