class Solution {
public:
    int solve(int i,int amt,vector<int>&coins,vector<vector<int>>&dp){
        if(amt==0) return 0;
        if(i>=coins.size() || amt<0) return INT_MAX;
        if(dp[amt][i]!=-1) return dp[amt][i];
        int call=solve(i,amt-coins[i],coins,dp);
        int inc=(call != INT_MAX) ? 1+call : INT_MAX;
        int exc=solve(i+1,amt,coins,dp);
        return dp[amt][i]=min(inc,exc);
    }
    int coinChange(vector<int>& coins, int amt) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=coins.size() ;
        vector<vector<int>>dp(amt+1 ,vector<int>(n,0));
        for(int j=0;j<n;j++) dp[0][j]=0;
        for(int i=1;i<=amt;i++){
            for(int j=n-1;j>=0;j--){
                dp[i][j]=1e9;
                int inc=1e9 , exc=1e9;
                if(i>=coins[j]) inc=1+dp[i-coins[j]][j];
                if(j+1<n) exc=dp[i][j+1];
                dp[i][j]=min(inc , exc);
            }
        }
        return dp[amt][0]>=1e9 ? -1:dp[amt][0];
    }
};