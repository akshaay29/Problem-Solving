class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(intervals.begin(),intervals.end(), [](auto &a,auto &b){ return a[1]<b[1];});
        int cnt=0 , prev_time=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<prev_time) cnt+=1;
            else prev_time=intervals[i][1];
        }
        return cnt;
    }
};