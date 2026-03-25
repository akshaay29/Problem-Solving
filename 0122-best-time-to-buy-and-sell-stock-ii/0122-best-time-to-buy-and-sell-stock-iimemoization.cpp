class Solution {
public:
    int solve(int i,int buy,int pf,vector<int>&prices,vector<vector<int>>&dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            pf+=max(-prices[i]+solve(i+1,0,pf,prices,dp),0+solve(i+1,1,pf,prices,dp));
        }
        else{
            pf+=max(prices[i]+solve(i+1,1,pf,prices,dp),0+solve(i+1,0,pf,prices,dp));
        }
        return dp[i][buy]=pf;
    }
    int maxProfit(vector<int>& prices) {
        int pf=0;
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(0,1,pf,prices,dp);
    }
};