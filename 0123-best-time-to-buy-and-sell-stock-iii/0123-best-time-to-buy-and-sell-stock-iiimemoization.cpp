class Solution {
public:
    int solve(int i,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp){
        int n=prices.size() , pf=0;
        if(i==n) return 0;
        if(cap == 0) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy){
            pf=max(-prices[i]+solve(i+1,0,cap,prices,dp) , 0+solve(i+1,1,cap,prices,dp));
        }
        else{
            pf=max(prices[i]+solve(i+1,1,cap-1,prices,dp) , 0+solve(i+1,0,cap,prices,dp));
        }
        return dp[i][buy][cap]=pf;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size() , cap=2;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,cap,prices,dp);
    }
};