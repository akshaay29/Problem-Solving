class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(boxTypes.begin(),boxTypes.end(),[](auto &a,auto &b){return a[1]>b[1];});
        int cnt=0;
        for(int i=0;i<boxTypes.size();i++){
            int pick=min(truckSize,boxTypes[i][0]);
            cnt+=(pick*boxTypes[i][1]);
            truckSize-=pick;
        }
        return cnt;
    }
};