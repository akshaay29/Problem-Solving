class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1) return {{1}};
        vector<vector<int>>dp(numRows,vector<int>(numRows,1));
        vector<vector<int>>ans;
        for(int i=1;i<numRows;i++){
            vector<int>comb(numRows,1);
            for(int j=1;j<i;j++){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            }
        }
        for(int i=0;i<numRows;i++){
            vector<int>comb;
            for(int j=0;j<i+1;j++)  comb.push_back(dp[i][j]);
            ans.push_back(comb);
        }
        return ans;
    }
};