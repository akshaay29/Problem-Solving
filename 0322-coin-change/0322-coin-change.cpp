class Solution {
public:
    /*int solve(int i,int amt,vector<int>& coins,vector<vector<int>>&dp){
        if(amt==0) return 0;
        if(amt<0 || i==coins.size()) return 1e9;
        if(dp[i][amt]!=-1) return dp[i][amt];
        int pick=1e9;
        if(amt>=coins[i]) pick=1+solve(i,amt-coins[i],coins,dp);
        int notpick=solve(i+1,amt,coins,dp);
        return dp[i][amt]=min(pick,notpick);
    }*/
    int coinChange(vector<int>& coins, int amount) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=coins.size();
        /*vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=solve(0,amount,coins,dp);
        return (ans==1e9) ? -1:ans;*/
        vector<vector<int>>dp(n+1,vector<int>(amount+1,1e9));
        for(int i=0;i<coins.size();i++){
            dp[i][0]=0;
        }
        for(int amt=1;amt<=amount;amt++){
            for(int i=n-1;i>=0;i--){
                int pick=INT_MAX;
                if(amt>=coins[i]) pick=1+dp[i][amt-coins[i]];
                dp[i][amt]=min(pick,dp[i+1][amt]);
            }
        }
        return (dp[0][amount]==1e9) ? -1:dp[0][amount];
    }
};