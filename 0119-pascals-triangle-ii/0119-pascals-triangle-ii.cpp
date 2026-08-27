class Solution {
public:
    vector<int> getRow(int r) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int>prev={1};
        for(int i=0;i<r+1;i++){
            vector<int>curr(i+1,1);
            for(int j=1;j<i;j++) curr[j]=prev[j-1]+prev[j];
            prev=curr;
        }
        return prev;
    }
};