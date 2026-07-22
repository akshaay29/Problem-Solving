class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>result;
        int prev_end=intervals[0][1] , prev_start=intervals[0][0];
        result.push_back({prev_start,prev_end});
        for(int i=1;i<intervals.size();i++){
            int curr_start=intervals[i][0] , curr_end=intervals[i][1];
            if(prev_end>=curr_start){
                result.back()[1]=max(result.back()[1],curr_end);
                prev_end=max(curr_end,prev_end);
            }
            else{
                result.push_back({curr_start,curr_end});
                prev_end=curr_end;
            }
        }
        return result;
    }
};