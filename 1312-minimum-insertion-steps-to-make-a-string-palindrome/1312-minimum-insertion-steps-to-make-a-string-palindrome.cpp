class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<=n-1;j++){
                if(i==j) dp[i][j]=0;
                else if(s[i]!=s[j]) dp[i][j]=1+min(dp[i][j-1] , dp[i+1][j]);
                else dp[i][j]=dp[i+1][j-1];
            }
        }
        return dp[0][n-1];
    }
};