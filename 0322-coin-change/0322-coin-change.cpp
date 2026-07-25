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
        int n=coins.size();
        vector<vector<int>>dp(amt+1 ,vector<int>(n,-1));
        int res=solve(0,amt,coins,dp);
        return (res==INT_MAX) ? -1:res;
    }
};