class Solution {
public:
    int solve(int i,int amt,vector<vector<int>>&dp,vector<int>&coins){
        if(amt==0) return 1;
        if(i==coins.size() && amt!=0) return 0;
        if(dp[i][amt]!=-1) return dp[i][amt];
        int pick=(amt>=coins[i]) ? solve(i,amt-coins[i],dp,coins):0;
        int notpick=solve(i+1,amt,dp,coins);
        return dp[i][amt]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return solve(0,amount,dp,coins);
    }
};