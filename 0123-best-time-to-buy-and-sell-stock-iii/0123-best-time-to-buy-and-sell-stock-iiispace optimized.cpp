class Solution {
public:
    /*int solve(int i,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp){
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
    }*/
    /*int maxProfit(vector<int>& prices) {
        int n=prices.size() , cap=2;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    int pf=0;
                    if(buy){
                        pf=max(-prices[i]+dp[i+1][0][cap] , dp[i+1][1][cap]);
                    }
                    else{
                        pf=max(prices[i]+dp[i+1][1][cap-1] , dp[i+1][0][cap]);
                    }
                    dp[i][buy][cap]=pf;
                }
            }
        }
        return dp[0][1][2];
    }*/
    int maxProfit(vector<int>& prices){
        vector<vector<int>>curr(2,vector<int>(3,0));
        vector<vector<int>>after(2,vector<int>(3,0));
        int n=prices.size();
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    int pf=0;
                    if(buy){
                        pf=max(-prices[i]+after[0][cap],after[1][cap]);
                    }
                    else pf=max(prices[i]+after[1][cap-1],after[0][cap]);
                    curr[buy][cap]=pf;
                }
            }
            after=curr;
        }
        return curr[1][2];
    }
};