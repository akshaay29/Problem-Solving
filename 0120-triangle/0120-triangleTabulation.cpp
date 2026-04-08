class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int j=0;j<triangle[n-1].size();j++) dp[n-1][j]=triangle[n-1][j];
        for(int i=n-1;i>=0;i--){
            int end=triangle[i].size();
            for(int j=end-1;j>=0;j--){
                if(i==n-1) dp[i][j]=triangle[i][j];
                else dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};