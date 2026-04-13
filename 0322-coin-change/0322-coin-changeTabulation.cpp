class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
        vector<int>dp(amt+1,1e9);
        dp[0]=0;
        for(int i=1;i<=amt;i++){
            for(int coin:coins){
                if(i>=coin) dp[i]=min(dp[i], 1+dp[i-coin]);
            }
        }
        return (dp[amt]!=1e9 ? dp[amt]:-1);
    }
};